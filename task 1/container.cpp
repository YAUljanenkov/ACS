#include "container.h"
#include "number.h"

void Init(container &c) {
    c.len = 0;
}

void Clear(container &c) {
    for (int i = 0; i < c.len; i++) {
        delete c.cont[i];
    }
    c.len = 0;
}

void In(container &c, FILE *in) {
    int n;
    fscanf(in, "%d", &n);
    for (int i = 0; i < n; ++i) {
        if ((c.cont[c.len] = In(in)) != 0) {
            c.len++;
        }
    }
}

void InRnd(container &c, int size) {
    while (c.len < size) {
        if ((c.cont[c.len] = InRnd()) != nullptr) {
            c.len++;
        }
    }
}

void Out(container &c, FILE *out) {
    fprintf(out, "Container contains ");
    fprintf(out, "%d", c.len);
    fprintf(out, "%s", " elements.\n");
    for (int i = 0; i < c.len; i++) {
        fprintf(out, "%d", i);
        fprintf(out, "%s", ": ");
        Out(*(c.cont[i]), out);
    }
}


void Merge(number *a[], int left_border, int divider, int right_border) {
    int l = left_border;
    int m = divider + 1;
    int r = 0;
    number *temp[right_border - left_border + 1];
    while (l <= divider && m <= right_border) {
        if (Decimal(*a[l]) < Decimal(*a[m]))
            temp[r++] = a[l++];
        else
            temp[r++] = a[m++];
    }
    while (m <= right_border)
        temp[r++] = a[m++];
    while (l <= divider)
        temp[r++] = a[l++];
    for (r = 0; r < right_border - left_border + 1; r++)
        a[left_border + r] = temp[r];
}

void Sort(number *a[], int left_border, int right_border) {
    int divider;
    if (left_border < right_border) {
        divider = (left_border + right_border) / 2;
        Sort(a, left_border, divider);
        Sort(a, divider + 1, right_border);
        Merge(a, left_border, divider, right_border);
    }
}

void StraightMerge(container &c, FILE *out) {
    Sort(c.cont, 0, c.len - 1);
    fprintf(out, "%s", "Container was sorted by straight merge sort\n");
    Out(c, out);
}

