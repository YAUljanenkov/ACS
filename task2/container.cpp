#include "container.h"
#include "number.h"

container::container() {
    len = 0;
}

void container::Clear() {
    for (int i = 0; i < len; i++) {
        delete cont[i];
    }
    len = 0;
}

void container::In(FILE *in) {
    int n;
    fscanf(in, "%d", &n);
    for (int i = 0; i < n; ++i) {
        if ((cont[len] = cont[len]->GetNumber(in)) != nullptr) {
            len++;
        }
    }
}

void container::InRnd(int size) {
    while (len < size) {
        if ((cont[len] = number::GetRandomNumber()) != nullptr) {
            len++;
        }
    }
}

void container::Out(FILE *out) {
    fprintf(out, "Container contains ");
    fprintf(out, "%d", len);
    fprintf(out, "%s", " elements.\n");
    for (int i = 0; i < len; i++) {
        fprintf(out, "%d", i);
        fprintf(out, "%s", ": ");
        cont[i]->Out(out);
    }
}


void Merge(number *a[], int left_border, int divider, int right_border) {
    int l = left_border;
    int m = divider + 1;
    int r = 0;
    number *temp[right_border - left_border + 1];
    while (l <= divider && m <= right_border) {
        if (a[l]->Decimal() < a[m]->Decimal())
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

void container::StraightMerge(FILE *out) {
    Sort(cont, 0, len - 1);
    fprintf(out, "%s", "Container was sorted by straight merge sort\n");
    Out(out);
}

