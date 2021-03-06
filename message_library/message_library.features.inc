<?php
/**
 * @file
 * message_library.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function message_library_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "boxes" && $api == "box") {
    return array("version" => "1");
  }
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function message_library_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function message_library_node_info() {
  $items = array(
    'message' => array(
      'name' => t('Message'),
      'base' => 'node_content',
      'description' => t('Use <em>Message</em> for creating message in <strong>Message Library</strong>'),
      'has_title' => '1',
      'title_label' => t('Information Requirement'),
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implements hook_default_search_api_autocomplete_search().
 */
function message_library_default_search_api_autocomplete_search() {
  $items = array();
  $items['search_api_views_message_library'] = entity_import('search_api_autocomplete_search', '{
    "machine_name" : "search_api_views_message_library",
    "name" : "Message Library",
    "index_id" : "message_library_index",
    "type" : "search_api_views",
    "enabled" : "1",
    "options" : { "result count" : true, "results" : 1 },
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_index().
 */
function message_library_default_search_api_index() {
  $items = array();
  $items['message_library_index'] = entity_import('search_api_index', '{
    "name" : "Message Library Index",
    "machine_name" : "message_library_index",
    "description" : null,
    "server" : "solr_server",
    "item_type" : "node",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "-1",
      "fields" : {
        "nid" : { "type" : "integer" },
        "vid" : { "type" : "integer" },
        "type" : { "type" : "string" },
        "title" : { "type" : "text" },
        "status" : { "type" : "boolean" },
        "created" : { "type" : "date" },
        "changed" : { "type" : "date" },
        "author" : { "type" : "integer", "entity_type" : "user" },
        "feed_nid" : { "type" : "integer" },
        "field_message_audience" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_message_group_mess" : { "type" : "text" },
        "field_message_group_risk" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_message_info_type" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_message_sensitivity" : { "type" : "integer" },
        "field_message_threat" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_message_synonyms" : { "type" : "text" },
        "search_api_language" : { "type" : "string" },
        "search_api_aggregation_1" : { "type" : "text" },
        "field_message_threat:tid" : { "type" : "integer" },
        "field_message_threat:name" : { "type" : "string" },
        "field_message_threat:description" : { "type" : "text" },
        "field_message_threat:field_threat_category" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_message_threat:field_threat_hazard" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_message_threat:field_threat_sector" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_message_threat:field_threat_category:tid" : { "type" : "list\\u003Cinteger\\u003E" },
        "field_message_threat:field_threat_category:name" : { "type" : "list\\u003Ctext\\u003E" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : { "default" : "0", "bundles" : { "message" : "message" } }
        },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "search_api_aggregation_1" : {
                "name" : "threat_title_fulltext",
                "type" : "fulltext",
                "fields" : [ "field_message_threat:name" ],
                "description" : "A Fulltext aggregation of the following fields: Threat \\u00bb Name."
              },
              "search_api_aggregation_2" : {
                "name" : "issue_title_fulltext",
                "type" : "fulltext",
                "fields" : [ "field_message_threat:field_threat_category:name" ],
                "description" : "A Fulltext aggregation of the following fields: Threat \\u00bb Issue \\u00bb Name."
              }
            }
          }
        }
      },
      "processors" : {
        "message_library_aggregate_parent_terms" : {
          "status" : 1,
          "weight" : "-50",
          "settings" : { "fields" : {
              "field_message_threat:field_threat_category:tid" : true,
              "field_message_threat:field_threat_category:name" : true
            }
          }
        },
        "search_api_case_ignore" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : { "field_message_threat:name" : true } }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : { "field_message_threat:name" : true },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : { "fields" : [], "spaces" : "[^[:alnum:]]", "ignorable" : "[\\u0027]" }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : { "field_message_threat:name" : true },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "highlight" : "always"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}
