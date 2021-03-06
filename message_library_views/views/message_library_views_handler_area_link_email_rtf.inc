<?php

/**
 * @file
 */

/**
 * Views area handler.
 *
 * @see: message_library_views_handler_area_link_rtf
 */
class message_library_views_handler_area_link_email_rtf extends views_handler_area {
  function option_definition() {
    $options = parent::option_definition();

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
  }

  function render($empty = FALSE) {
    $output = '';

    // For view 'messsage_library_threat'
    if ($this->view->name == 'messsage_library_threat') {
      $threat_tids = array(reset($this->view->args));
    }
    else {
      // Get total.
      $total = $this->view->total_rows;
      // Cache ID.
      // TODO: make it unique?
      $cache_id = 'message_library_views';
      // Get all results, with Search API.
      if (!empty($total)) {
        $query = $this->query;
        if (!empty($query) && ($query instanceof SearchApiViewsQuery)) {
          $threat_terms = message_library_views_search_all_threat($cache_id, $query);
          $threat_tids = array_keys($threat_terms);
        }
      }
    }

    if (!empty($threat_tids)) {
      // The href need to open the email client
      $href_prefix = 'mailto:?body=' . t('Download the RTF from the server at the URL: ');
      $threat_seg = drupal_encode_path(implode(',', $threat_tids));
      $href = url('message-library-rtf/threat/' . $threat_seg, array('absolute' => TRUE));

      $output .= '<div class="download_email_email_rtf_box">'
        . l(t('Email as an RTF'), $href_prefix . $href)
        . '</div>';
    }

    return $output;
  }
}
