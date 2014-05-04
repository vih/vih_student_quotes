<?php

/**
 * @file
 *  Migrations for vih_participant_quote.
 */

class VIHStudentQuoteNode extends VIHMigration {

  public function __construct() {
    parent::__construct();
    $this->description = t('Import participant quotes.');

    // Create a map object for tracking the relationships between source rows
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'id' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
        ),
      ),
      MigrateDestinationNode::getKeySchema()
    );

    // Create a MigrateSource object.
    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'vih_student_quotes') . '/import/quotes.csv', $this->csvcolumns(), array('header_rows' => 1));

    $this->destination = new MigrateDestinationNode('vih_long_course_quotes');

    $this->addFieldMapping('uid', 'uid')->defaultValue(1);

    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('body', 'body');
    $this->addFieldMapping('body:format')
      ->defaultValue('panopoly_wysiwyg_text');

    $this->addFieldMapping('field_student_quote_category', 'course_type');
    $this->addFieldMapping('field_student_quote_category:create_term')
      ->defaultValue(TRUE);

    // Featured image
    $this->addFieldMapping('field_profile_picture', 'featured_image');
    $this->addFieldMapping('field_profile_picture:file_replace')
      ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('field_profile_picture:source_dir')
      ->defaultValue(drupal_get_path('module', 'vih_student_quotes') . '/import/images');
  }

  function csvcolumns() {
    $columns[0] = array('id', 'Id');
    $columns[1] = array('title', 'Title');
    $columns[2] = array('body', 'Body');
    $columns[3] = array('course_type', 'Course Type');
    $columns[4] = array('featured_image', 'Featured Image');
    return $columns;
  }
}
