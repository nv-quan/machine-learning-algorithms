#include "data.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

void
log_point(Point *p) {
  int i;

  printf("[POINT] y: %lf, x: ", p->y);
  for (i = 0; i < p->x_length; ++i) {
    printf("%lf%s", p->x[i], i < p->x_length - 1 ? " " : "\n");
  }
}

Mat *
creat_mat(size_t row, size_t col) {
  if (row * col == 0) {
    return NULL;
  }
  double *val = (double *)safe_malloc(sizeof(*val) * row * col);
  Mat *mat = (Mat *)safe_malloc(sizeof(*mat));
  mat->row = row;
  mat->col = col;
  mat->val = val;
  return mat;
}

void
destr_mat(Mat *mat) {
  safe_free((void **)&mat->val);
  safe_free((void **)&mat);
}

Mat *
creat_mat_from_val(double *val, size_t row, size_t col) {
  Mat *res = creat_mat(row, col);
  memcpy((void *)res->val, (const void *)val, sizeof(double) * row * col);
  return res;
}

void
set_mat_elem(Mat *mat, size_t i, size_t j, double val) {
  mat->val[i * mat->col + j] = val;
}

double
get_mat_elem(Mat *mat, size_t i, size_t j) {
  return mat->val[i * mat->col + j];
}

void
set_mat_row(Mat *mat, size_t row_idx, double *value) {
  double *row = mat->val + mat->col * row_idx;
  memcpy((void *)row, (const void *)value, sizeof(double) * mat->col);
}

void
set_mat_col(Mat *mat, size_t col_idx, double *value) {
  size_t i;
  for (i = 0; i < mat->row; ++i) {
    set_mat_elem(mat, i, col_idx, value[i]);
  }
}
