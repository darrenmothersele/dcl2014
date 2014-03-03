<?php
/**
 * @file
 * dcl2014.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function dcl2014_default_rules_configuration() {
  $items = array();
  $items['rules_complete_birthplace_reference'] = entity_import('rules_config', '{ "rules_complete_birthplace_reference" : {
      "LABEL" : "Complete birthPlace reference",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "person" : { "label" : "Person", "type" : "node" } },
      "IF" : [
        { "node_is_of_type" : { "node" : [ "person" ], "type" : { "value" : { "person" : "person" } } } }
      ],
      "DO" : [
        { "entity_query" : {
            "USING" : {
              "type" : "node",
              "property" : "field_dbpedia",
              "value" : [ "person:field-dbpedia-place" ],
              "limit" : "1"
            },
            "PROVIDE" : { "entity_fetched" : { "entity_fetched" : "Fetched entity" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "entity-fetched" ] },
            "ITEM" : { "list_item" : "Current list item" },
            "DO" : [
              { "data_set" : { "data" : [ "person:field-place-of-birth" ], "value" : [ "list-item" ] } }
            ]
          }
        }
      ]
    }
  }');
  $items['rules_link_people_and_places'] = entity_import('rules_config', '{ "rules_link_people_and_places" : {
      "LABEL" : "Link People and Places",
      "PLUGIN" : "action set",
      "OWNER" : "rules",
      "REQUIRES" : [ "views_bulk_operations", "rules_batch", "rules" ],
      "ACTION SET" : [
        { "views_bulk_operations_action_load_list" : {
            "USING" : { "view" : "select_all_people|default" },
            "PROVIDE" : { "entity_list" : { "entity_list" : "A list of entities" } }
          }
        },
        { "BATCH LOOP" : {
            "USING" : { "list" : [ "entity-list" ] },
            "ITEM" : { "list_item" : "Current list item" },
            "DO" : [
              { "component_rules_complete_birthplace_reference" : { "person" : [ "list-item" ] } }
            ]
          }
        }
      ]
    }
  }');
  return $items;
}
