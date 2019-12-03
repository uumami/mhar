/* ----------------------- Prototype functions ------------------------------ */

/***************************  count_rows *************************************
  * This functions counts how many lines (rows) a txt file has.
    It will be used by the function count_restrictions.
  * Requirements: None
  * Inputs:
      + The separtor between lines (rows) must be different from the varaible
        (column) separator. We recomend using the new line character.
      + Pointer to the txt File.
  * Output:
      + Returns and unsigned integer with the number of lines (rows)
      in the txt file.
*******************************************************************************/
unsigned count_rows(FILE *file);



/***************************  count_columns *************************************
  * This functions counts how many numbers per line (column) a txt file has.
    It will be used by the function count_restrictions.
  * Requirements: None
  * Inputs:
      + The separtor between values (colums) must be different from the line
        (rows) separator. We recomend using comas, spaces or pipes.
      + Pointer to the txt File.
  * Output:
      + Returns and unsigned integer with the number of variables (columns)
      in the txt file.
*******************************************************************************/
unsigned count_columns(FILE *file);
