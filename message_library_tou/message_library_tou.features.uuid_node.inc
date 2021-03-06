<?php
/**
 * @file
 * message_library_tou.features.uuid_node.inc
 */

/**
 * Implements hook_uuid_features_default_content().
 */
function message_library_tou_uuid_features_default_content() {
  $nodes = array();

  $nodes[] = array(
  'uid' => 1,
  'title' => 'Message Library Terms of Use',
  'log' => '',
  'status' => 1,
  'comment' => 1,
  'promote' => 1,
  'sticky' => 0,
  'vuuid' => '1343ff2d-6c71-42cf-a56b-18fe1a428ba3',
  'title_original' => 'Message Library Terms of Use',
  'type' => 'page',
  'language' => 'und',
  'created' => 1377607256,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '85f259f3-7183-4f53-9f76-ff00c1b009dc',
  'reliefweb' => 0,
  'revision_uid' => 1,
  'base_reliefweb' => 0,
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<p>Welcome to infoasaid\'s message library. This is an online searchable database of messages that acts as a reference for those wanting to disseminate critical information to affected populations in an </p>
<p>It has been developed in collaboration with a number of different clusters/sectors in humanitarian response including Health, Water, Sanitation and Hygiene (WASH), Nutrition, Food Security, Protection (Child Protection, Gender-based Violence, Mine Risk Education), Education and Camp Coordination Camp Management (natural disaster). The message library can be used both as a disaster preparedness tool and following the outbreak of an emergency. If used in the correct way, the library should help improve communication with crisis-affected populations.</p>

<p><strong>Preparedness</strong></p>
<p>As a preparedness exercise, you can:</p>
<ul>
  <li>Involve communities to identify threats and draft appropriatemessages using the message library as a reference</li>
  <li>Pre-test the messages with different segments of society (consider differences in gender, rural/urban, education levels, age) to ensure comprehension</li>
  <li>Prepare communication materials for use in either disaster risk reduction or emergency response</li>
  <li>Train colleagues in communication skills and message delivery</li>
</ul>

<p><strong>Response</strong></p>
<p>Once an emergency has broken, and before programmes and supplies have been organised, you can help disseminate important and useful information to the affected populations. The message library acts as a reference to what can be disseminated such as:</p>
<ul>
  <li>Information about the scale, nature and impact of the disaster (humanitarian news)</li>
  <li>Alerts about secondary disasters such as aftershocks, landslides or flooding</li>
  <li>Messages about how to stay safe and mitigate risk in the face of anticipated threats</li>
</ul>

<p>Once there is a more accurate picture about the actual needs of the community through either inter-agency rapid needs assessments or individual agency assessments (including their communications needs) and your aid agency designs a response programme you can send out the following types of messages:</p>
<p>Messages about your agency and programme activities, and how, where and when communities can access your services.</p>
<p>Messages aimed to raise awareness about specific issues</p>

<p><strong>Contextualisation</strong></p>
<p>Before disseminating a message, it is essential to understand the context you are working in. &nbsp;By contextualising each message, it helps to avoid any potential harm that can be created by sending out the wrong information. Consider:</p>
<ol>
  <li>Language: Use words that the affected population understands, keep the language positive, avoid scaremongering and remember to use simple, every day words and keep the message concise.&nbsp;</li>
  <li>Existing knowledge: Knowing the level of education and knowledge of the people affected will help you in choosing and adapting the appropriate message. You may need to combine awareness raising messages alongside self-care or service so that affected populations are given enough information to make informed choices.</li>
  <li>Cultural beliefs and practices: Knowing and understanding the cultural beliefs and practices of the crisis affected community is very important. Some of these beliefs may act as barriers to what you are trying to achieve.</li>
  <li>Feasibility: Messages need to be providing information that people find useful and/or can act upon. There is no point crafting a message that tells people to do something when the situation on the ground makes it impossible for them to follow that advice.</li>
</ol>

<p><strong>Translation and Pilot testing messages</strong></p>
<p>All messages will need to be translated into the language(s) the affected population understands, preferably their mother tongue. Pilot-testing with affected communities aims to ensure that messages are understandable, acceptable, relevant, and persuasive. It will also help prevent the dissemination of either meaningless or potentially harmful information.</p>

<p><strong>Identifying the most appropriate channels of communication</strong></p>
<p>Some messages are appropriate for certain channels of communication, other messages are not. For example, it would not be advisable to send out SMS messages to a largely illiterate population. <a href="http://www.infoasaid.org/sites/infoasaid.org/files/characteristics_of_different_communication_channels-1.pdf" target="_self">Download guidance on the characteristics of different communication channels</a> and <a href="http://infoasaid.org/diagnostic-tools" target="_self">visit our&nbsp;diagnostic tools</a> that you can use to assess the feasibility of different channels of communication.</p>

<p><strong>More information</strong></p>
<p>For more information on the message library go to the <a href="http://iaa.e-nuksuk.com/faq">frequently asked questions</a> section or <a href="http://www.infoasaid.org/sites/infoasaid.org/files/message_library_guide_june_2012.pdf" target="_blank">download the comprehensive guide</a> which accompanies the message library.</p>

<p><strong>Access</strong></p>
<p>There are two ways to access the library.</p>
<p>1) If you tick the "I accept" box, followed by "GO", this means that every time you access the library you will have to read the terms and conditions and scroll down to tick the box.</p>
<p>2) If you tick the "I accept" AND the \'I want to register" box, this will take you through to a registration page. Once you have filled in your details and received a confirmation email, you will always have immediate access to the database.</p>
',
        'summary' => '',
        'format' => 'full_html',
      ),
    ),
  ),
  'title_field' => array(
    'und' => array(
      0 => array(
        'value' => 'Message Library Terms of Use',
        'format' => NULL,
        'safe_value' => 'Message Library Terms of Use',
      ),
    ),
  ),
  'rdf_mapping' => array(
    'rdftype' => array(
      0 => 'sioc:Item',
      1 => 'foaf:Document',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
  ),
  'translations' => array(
    'original' => NULL,
    'data' => array(),
  ),
  'cid' => 0,
  'last_comment_name' => NULL,
  'last_comment_uid' => 1,
  'comment_count' => 0,
  'name' => 'guillaumev',
  'picture' => 0,
  'data' => 'b:0;',
  'date' => '2013-08-27 14:40:56 +0200',
);
  return $nodes;
}
