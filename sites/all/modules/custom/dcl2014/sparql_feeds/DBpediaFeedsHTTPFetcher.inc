<?php

class DBpediaFeedsHTTPFetcherResult extends FeedsHTTPFetcherResult {
  protected $query;

  public function __construct($query = NULL) {
    $this->query = $query;
    $get = array(
      'format' => 'text/csv',
      'timeout' => '30000',
      'default-graph-uri' => 'http://dbpedia.org',
      'query' => $this->query,
    );
    $url = 'http://dbpedia.org/sparql?' . http_build_query($get);
    parent::__construct($url);
  }
}


class DBpediaFeedsHTTPFetcher extends FeedsHTTPFetcher {

  public function fetch(FeedsSource $source) {
    $source_config = $source->getConfigFor($this);
    $fetcher_result = new DBpediaFeedsHTTPFetcherResult($source_config['query']);
    // When request_timeout is empty, the global value is used.
    $fetcher_result->setTimeout($this->config['request_timeout']);
    return $fetcher_result;
  }

  public function configDefaults() {
    return parent::configDefaults() + array(
      'execution_timeout' => '30000',
      'results_format' => 'text/csv',
      'default_graph_uri' => 'http://dbpedia.org',
      'sparql_endpoint' => 'http://dbpedia.org/sparql',
    );
  }

  public function configForm(&$form_state) {
    $form = array();
    $form['request_timeout'] = array(
      '#type' => 'textfield',
      '#title' => t('Request timeout'),
      '#description' => t('Timeout in seconds to wait for an HTTP get request to finish.</br>' .
                       '<b>Note:</b> this setting will override the global setting.</br>' .
                       'When left empty, the global value is used.'),
      '#default_value' => $this->config['request_timeout'],
      '#element_validate' => array('element_validate_integer_positive'),
      '#maxlength' => 3,
      '#size'=> 30,
    );
    return $form;
  }

  /**
   * Expose source form.
   */
  public function sourceForm($source_config) {
    $form = array();
    $form['query'] = array(
      '#type' => 'textarea',
      '#title' => t('DBpedia SPARQL Query'),
      //'#description' => t(''),
      '#default_value' => isset($source_config['query']) ? $source_config['query'] : '',
    );
    return $form;
  }

  public function sourceFormValidate(&$values) {
    return TRUE;
  }
}

