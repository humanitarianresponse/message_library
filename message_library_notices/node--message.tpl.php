<?php
/**
 * @file
 * Custom theme implementation to display a node of type - 'Message'
 *
 * The origial template has:
 * - An anchor with the message node nid, so it can't quickly located under a
 *   threat.
 * - A class 'message_highlight' on the outter div, so that any hightlighting
 *   css style can be easily applied
 * - Provide a edit link if the user has access for it, this seems not necessary
 *   in D7
 * - Sensitivity warning block
 * - Search highlight links
 */
?>
<a name="<?php print $node->nid ?>"></a>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <?php if (!$page): ?>
    <?php print render($title_prefix); ?>
    <h2<?php print $title_attributes; ?>><?php print $title; ?></h2>
    <?php print render($title_suffix); ?>

    <div class="clearfix">
      <?php print $user_picture; ?>

      <?php if (!empty($sensitivity_warning)): ?>
        <?php print $sensitivity_warning; ?>
      <?php endif; ?>

      <div class="content"<?php print $content_attributes; ?>>
        <?php
          hide($content['links']);
          if (!empty($hide_message_content)) {
            hide($content['field_message_group_mess']);
          }
          print render($content);
        ?>
      </div>

      <div class="highlight-nav">
        <?php if (!empty($prev_highlighted_message)): ?>
          <?php print $prev_highlighted_message; ?>
        <?php endif; ?>

        <?php if (!empty($next_highlighted_message)): ?>
          <?php print $next_highlighted_message; ?>
        <?php endif; ?>
      </div>
    </div>
  <?php endif; ?>
</div>
