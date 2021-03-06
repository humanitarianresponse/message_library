<?php
/**
 * @file
 * message_library.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function message_library_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'message_library_admin';
  $context->description = 'Displays Admin Box on \'Message Library\' search relevant pages.';
  $context->tag = 'message library';
  $context->conditions = array(
    'user' => array(
      'values' => array(
        'administrator' => 'administrator',
        'editor' => 'editor',
        'manager' => 'manager',
      ),
    ),
    'views' => array(
      'values' => array(
        'message_library:page_1' => 'message_library:page_1',
        'message_library:page_2' => 'message_library:page_2',
        'message_library:search_page' => 'message_library:search_page',
        'messsage_library_threat' => 'messsage_library_threat',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-message_library_admin' => array(
          'module' => 'boxes',
          'delta' => 'message_library_admin',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
    'theme_html' => array(
      'class' => 'message-library',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Displays Admin Box on \'Message Library\' search relevant pages.');
  t('message library');
  $export['message_library_admin'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'message_library_search';
  $context->description = 'Displayed on \'Message Library\' search relevant pages.';
  $context->tag = 'message library';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'message_library:search_page' => 'message_library:search_page',
        'messsage_library_threat' => 'messsage_library_threat',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-message_library_about' => array(
          'module' => 'boxes',
          'delta' => 'message_library_about',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
    'theme_html' => array(
      'class' => 'message-library',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Displayed on \'Message Library\' search relevant pages.');
  t('message library');
  $export['message_library_search'] = $context;

  return $export;
}
