#include <stdio.h>
#include <stdlib.h>

#define MAX_CODE_LEN 100

typedef struct Node {
    char ch;
    int freq;
    struct Node *l, *r;
} Node;

Node* new_node(char c, int f) {
    Node* n = malloc(sizeof(Node));
    n->ch   = c;
    n->freq = f;
    n->l = n->r = NULL;
    return n;
}

int cmp_node(const void *a, const void *b) {
    Node *na = *(Node**)a;
    Node *nb = *(Node**)b;
    return na->freq - nb->freq;
}

void print_codes(Node *root, char code[], int depth) {
    if (!root) return;
    if (!root->l && !root->r) {
        code[depth] = '\0';
        printf("'%c' -> %s\n", root->ch, code);
    } else {
        code[depth] = '0';
        print_codes(root->l, code, depth+1);
        code[depth] = '1';
        print_codes(root->r, code, depth+1);
    }
}

int main(void) {
    int n;
    printf("Enter number of characters: ");
    if (scanf("%d", &n)!=1 || n<=0) return 0;

    // read inputs
    char *chars = malloc(n);
    int  *freqs = malloc(n * sizeof(int));
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("Character %d: ", i+1);
        scanf(" %c", &chars[i]);
        printf("Frequency of '%c': ", chars[i]);
        scanf("%d", &freqs[i]);
        printf("\n");
    }

    Node **arr = malloc(n * sizeof(Node*));
    for (int i = 0; i < n; i++)
        arr[i] = new_node(chars[i], freqs[i]);

    int sz = n;
    while (sz > 1) {
        qsort(arr, sz, sizeof(Node*), cmp_node);
        Node *a = arr[0], *b = arr[1];
        Node *m = new_node('\0', a->freq + b->freq);
        m->l = a;  m->r = b;
        arr[1] = m;
        arr[0] = arr[sz-1];
        sz--;
    }

    printf("\nGenerated Huffman Codes:\n");
    char code[MAX_CODE_LEN];
    print_codes(arr[0], code, 0);

    return 0;
}
