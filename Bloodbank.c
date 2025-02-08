#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char blood_type[5];
    void* data;
    struct Node* left;
    struct Node* right;
} Node;

Node* insert(Node* root, char blood_type[], void* data) {
    if (root == NULL) {
        root = (Node*)malloc(sizeof(Node));
        strcpy(root->blood_type, blood_type);
        root->data = data;
        root->left = root->right = NULL;
    } else if (strcmp(blood_type, root->blood_type) < 0) {
        root->left = insert(root->left, blood_type, data);
    } else {
        root->right = insert(root->right, blood_type, data);
    }
    return root;
}

Node* search(Node* root, char blood_type[]) {
    if (root == NULL || strcmp(root->blood_type, blood_type) == 0) {
        return root;
    } else if (strcmp(blood_type, root->blood_type) < 0) {
        return search(root->left, blood_type);
    } else {
        return search(root->right, blood_type);
    }
}

void findDonors(Node* root, char blood_type[], void (*visit)(char[], void*)) {
    if (root == NULL) return;

    findDonors(root->left, blood_type, visit);

    if (strcmp(root->blood_type, "O-") == 0 || strcmp(root->blood_type, "O+") == 0 ||
        (strcmp(root->blood_type, "A-") == 0 && (strcmp(blood_type, "A-") == 0 || strcmp(blood_type, "A+") == 0)) ||
        (strcmp(root->blood_type, "B-") == 0 && (strcmp(blood_type, "B-") == 0 || strcmp(blood_type, "B+") == 0)) ||
        (strcmp(root->blood_type, "AB-") == 0 && (strcmp(blood_type, "AB-") == 0 || strcmp(blood_type, "AB+") == 0)) ||
        (strcmp(root->blood_type, "A+") == 0 && strcmp(blood_type, "A+") == 0) ||
        (strcmp(root->blood_type, "B+") == 0 && strcmp(blood_type, "B+") == 0) ||
        (strcmp(root->blood_type, "AB+") == 0 && strcmp(blood_type, "AB+") == 0)) {
        visit(root->blood_type, root->data);
    }

    findDonors(root->right, blood_type, visit);
}

void print_student_info(char blood_type[], void* data) {
    static int count = 0;
    count++;
    printf("%d. %s - Blood Type: %s\n", count, (char*)data, blood_type);
}

int main() {
    Node* root = NULL;

    root = insert(root, "A-", "Akhil - ak7099@srnist.edu.in");
    root = insert(root, "B-", "Nagoor - emily.ns77@srnist.edu.in");
    root = insert(root, "AB-", "Dhanush - dp5656@srnist.edu.in");
    root = insert(root, "O-", "Aakash - ak6959@srnist.edu.in");
    root = insert(root, "A+", "Darahas - p00099@srnist.edu.in");
    root = insert(root, "O+", "Udaya Harsha - ui8489@srnist.edu.in");
    root = insert(root, "AB-", "Samyak - sk@srnist.edu.in");
    root = insert(root, "B+", "Omkar - or2211@srnist.edu.in");

    char target_blood_type[5];
    printf("Enter the blood type to search for: ");
    scanf("%s", target_blood_type);

    Node* found = search(root, target_blood_type);
    if (found) {
        printf("Found student with blood type %s: %s\n", target_blood_type, (char*)found->data);
    } else {
        printf("Blood type %s not found\n", target_blood_type);
    }

    printf("Donors with compatible blood types:\n");
    findDonors(root, target_blood_type, print_student_info);

    return 0;
}
