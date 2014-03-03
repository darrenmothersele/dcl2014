<?php
/**
 * @file
 * dcl2014.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function dcl2014_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'dbpedia_person_importer';
  $feeds_importer->config = array(
    'name' => 'DBpedia Person Importer',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'DBpedia',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
        'execution_timeout' => '30000',
        'results_format' => 'text/csv',
        'default_graph_uri' => 'http://dbpedia.org',
        'sparql_endpoint' => 'http://dbpedia.org/sparql',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => 0,
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'subject',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'subject',
            'target' => 'field_dbpedia',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'label',
            'target' => 'title',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'b',
            'target' => 'field_dbpedia_place',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'link',
            'target' => 'field_homepage:url',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'img',
            'target' => 'field_image',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'comment',
            'target' => 'field_summary',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'abstract',
            'target' => 'body',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'person',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => 1800,
    'expire_period' => 3600,
    'import_on_create' => TRUE,
    'process_in_background' => FALSE,
  );
  $export['dbpedia_person_importer'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'dbpedia_place_importer';
  $feeds_importer->config = array(
    'name' => 'DBpedia Place Importer',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'DBpedia',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
        'execution_timeout' => '30000',
        'results_format' => 'text/csv',
        'default_graph_uri' => 'http://dbpedia.org',
        'sparql_endpoint' => 'http://dbpedia.org/sparql',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => 0,
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'subject',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'subject',
            'target' => 'field_dbpedia',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'label',
            'target' => 'title',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'lat',
            'target' => 'field_location:lat',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'long',
            'target' => 'field_location:lon',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'thumb',
            'target' => 'field_image',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'pop',
            'target' => 'field_population',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'comment',
            'target' => 'field_summary',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'abstract',
            'target' => 'body',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'link',
            'target' => 'field_homepage:url',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'place',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => 1800,
    'expire_period' => 3600,
    'import_on_create' => TRUE,
    'process_in_background' => FALSE,
  );
  $export['dbpedia_place_importer'] = $feeds_importer;

  return $export;
}
