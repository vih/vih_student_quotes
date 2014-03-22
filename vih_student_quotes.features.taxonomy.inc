<?php
/**
 * @file
 * vih_student_quotes.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function vih_student_quotes_taxonomy_default_vocabularies() {
  return array(
    'vih_student_quote_category' => array(
      'name' => 'Student Quote category',
      'machine_name' => 'vih_student_quote_category',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
