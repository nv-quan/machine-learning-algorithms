#include "algorithms/gradient_descent.h"
#include "config.h"
#include "data.h"
#include "io.h"
#include <stdio.h>

int main(void) {
  Config config = get_config();
  /* Data buffer[MAX_DATA_LENGTH]; */
  switch (config.algorithm) {
  case STOCHASTIC_GRADIENT_DESCENT:
    /* sgd(config); */
    break;
  case BATCH_GRADIENT_DESCENT:
    break;
  default:
    break;
  }
  /* display_result();*/
  return 0;
}
