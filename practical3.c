#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char cname[30];
    long long mob;
    struct node *link;
};

int main()
{
    struct node *start = NULL;
    struct node *p, *q, *r;
    char search_name[30];
    int ch;

    do
    {
        printf("\n--- CONTACT MENU ---");
        printf("\n1. Add Contact (First)");
        printf("\n2. Add Contact (Last)");
        printf("\n3. Delete Contact");
        printf("\n4. Search Contact");
        printf("\n5. Display Directory");
        printf("\n6. Exit");
        printf("\nEnter option: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            p = (struct node *)malloc(sizeof(struct node));
            printf("Enter Name: ");
            scanf("%s", p->cname);
            printf("Enter Mobile: ");
            scanf("%lld", &p->mob);
            p->link = start;
            start = p;
            printf("Contact inserted successfully.\n");
            break;

        case 2:
            p = (struct node *)malloc(sizeof(struct node));
            printf("Enter Name: ");
            scanf("%s", p->cname);
            printf("Enter Mobile: ");
            scanf("%lld", &p->mob);
            p->link = NULL;

            if (start == NULL)
            {
                start = p;
            }
            else
            {
                q = start;
                while (q->link != NULL)
                {
                    q = q->link;
                }
                q->link = p;
            }
            printf("Contact added at end.\n");
            break;

        case 3:
            if (start == NULL)
            {
                printf("List is empty.\n");
                break;
            }

            printf("Enter Name to remove: ");
            scanf("%s", search_name);

            q = start;
            r = NULL;

            while (q != NULL && strcmp(q->cname, search_name) != 0)
            {
                r = q;
                q = q->link;
            }

            if (q == NULL)
            {
                printf("Name not found in directory.\n");
            }
            else
            {
                if (r == NULL)
                {
                    start = q->link;
                }
                else
                {
                    r->link = q->link;
                }

                free(q);
                printf("Contact deleted.\n");
            }
            break;

        case 4:
            if (start == NULL)
            {
                printf("Directory is empty.\n");
                break;
            }

            printf("Enter Name to find: ");
            scanf("%s", search_name);

            q = start;
            while (q != NULL)
            {
                if (strcmp(q->cname, search_name) == 0)
                {
                    printf("Match Found!\n");
                    printf("Name: %s\n", q->cname);
                    printf("Mobile: %lld\n", q->mob);
                    break;
                }
                q = q->link;
            }

            if (q == NULL)
            {
                printf("No record found.\n");
            }
            break;

        case 5:
            if (start == NULL)
            {
                printf("No contacts to show.\n");
            }
            else
            {
                printf("\n--- Contact List ---\n");
                q = start;
                while (q != NULL)
                {
                    printf("Name: %s | Mobile: %lld\n", q->cname, q->mob);
                    q = q->link;
                }
            }
            break;

        case 6:
            printf("Terminating program...\n");
            break;

        default:
            printf("Invalid choice! Enter between 1-6.\n");
        }

    } while (ch != 6);

    return 0;
}
