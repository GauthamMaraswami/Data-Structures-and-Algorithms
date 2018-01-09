
#include<stdio.h>
#include<stdlib.h>
 
struct link {
    int coeff;
    int pow;
    struct link * next;
} my_poly;
 
struct link *poly1=NULL,*poly2=NULL,*poly3=NULL;






void my_create_poly(struct link *node) {
    int flag; 
    int coeff, pow;
    struct link *tmp_node; 
    tmp_node = (my_poly *) malloc(sizeof(my_poly)); 
    *node = tmp_node; 
    do {
        
        printf("\nEnter Coeff:");
        scanf("%d", &coeff);
        tmp_node->coeff = coeff;
        printf("\nEnter Pow:");
        scanf("%d", &pow);
        tmp_node->pow = pow;
        tmp_node->next = NULL;
 
        
        printf("\nContinue adding more terms to the polynomial list?(Y = 1/N = 0): ");
        scanf("%d", &flag);
       
        if(flag) {
            tmp_node->next = (my_poly *) malloc(sizeof(my_poly)); 
            tmp_node = tmp_node->next;
            tmp_node->next = NULL;
        }
    } while (flag);
}
 

void my_show_poly(my_poly * node) {
    printf("\nThe polynomial expression is:\n");
    while(node != NULL) {
        printf("%dx^%d", node->coeff, node->pow);
        node = node->next;
        if(node != NULL)
            printf(" + ");
    }
}
 

void my_add_poly(struct link *resultu, struct link *polyt,struct link *polyt1) {
    struct link *tmp_node; 
    tmp_node = (my_poly *) malloc(sizeof(my_poly));
    tmp_node->next = NULL;
    *resultu = tmp_node; 
    while(polyt && poly1) {
        if (polyt->pow > polyt1->pow) {
            tmp_node->pow = poly1->pow;
            tmp_node->coeff = polyt->coeff;
            polyt = polyt->next;
        }
        else if (polyt->pow < polyt1->pow) {
            tmp_node->pow = polyt1->pow;
            tmp_node->coeff = polyt1->coeff;
            polyt1 = polyt1->next;
        }
        else {
            tmp_node->pow = polyt->pow;
            tmp_node->coeff = polyt->coeff + polyt1->coeff;
            polyt = polyt->next;
            polyt1 = polyt1->next;
        }
         if(polyt && polyt1) {
            tmp_node->next = (my_poly *) malloc(sizeof(my_poly));
            tmp_node = tmp_node->next;
            tmp_node->next = NULL;
        }
    }
 
   
    while(polyt || polyt1) {
        
        tmp_node->next = (my_poly *) malloc(sizeof(my_poly));
        tmp_node = tmp_node->next;
        tmp_node->next = NULL;
 
        if(polyt) {
            tmp_node->pow = polyt->pow;
            tmp_node->coeff = polyt->coeff;
            polyt = polyt->next;
        }
        if(polyt1) {
            tmp_node->pow = polyt1->pow;
            tmp_node->coeff = polyt1->coeff;
            polyt1 = polyt1->next;
        }
    }
 
    printf("\nAddition Complete");
}

int main(void) {
    int ch;
    do {
       
 
        printf("\nCreate 1st expression\n");
        my_create_poly(poly1);
        printf("\nStored the 1st expression");
        my_show_poly(poly1);
 
        printf("\nCreate 2nd expression\n");
        my_create_poly(&poly2);
        printf("\nStored the 2nd expression");
        my_show_poly(poly2);
 
        my_add_poly(poly3, poly1, poly2);
        my_show_poly(poly3);
 
        printf("\nAdd two more expressions? (Y = 1/N = 0): ");
        scanf("%d", &ch);
    } while (ch);
    return 0;
}
 
