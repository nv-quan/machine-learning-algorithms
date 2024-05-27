#ifndef GRADIENT_DESCENT_H
#define GRADIENT_DESCENT_H

#include "io.h"

enum grad_desc_type { STOCHASTIC, BATCH };
enum comp_graph_type { LIN_REG /*Linear regression*/ };

/* Computational graph of cost function
 * Temporary use an enum to specify linear function.
 * TODO: Implement computational graph to handle different types of functions
 */
typedef struct computation_graph {
  enum comp_graph_type type;
} CompGraph;

/* Gradient descent config */
typedef struct grad_desc_config {
  /* Depending on the batch size, gradient descent will be
   * stochastics or batch. */
  size_t batch_size;

  /* Learning rate */
  double learn_rate;

  /* Cost function */
  enum comp_graph_type cost_func;

  /* Dimension of theta and input, or number of features + 1*/
  size_t dimension;

  /* Loss reporter: takes in epoch count and loss */
  void (*loss_reporter)(int, double);
} GDConf;

/* Run gradient descent to minimize cost function and return result into
 * a double array.
 *
 * config, ld_conf, and result are allocated and owned by caller.
 *
 * Return 1 when success and 0 when fail.
 */
int grad_desc(struct grad_desc_config *config,
              struct data_loader_config *ld_conf, double *result);

#endif /* ifndef GRADIENT_DESCENT_H */
