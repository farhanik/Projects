#include<stdio.h>
#include<stdlib.h>

#define MAX_EVENTS 100
typedef struct
{
    int day;
    int month;
    int year;
    char description[100];
} Event;

typedef struct
{
    Event events[MAX_EVENTS];
    int count;
} Calendar;
void addEvent(Calendar *calendar)
{
    if (calendar->count >= MAX_EVENTS)
    {
        printf("Calendar is full. Cannot add more events.\n");
        return;
    }

    Event newEvent;
    printf("Enter event details:\n");
    printf("Day: ");
    scanf("%d", &newEvent.day);
    printf("Month: ");
    scanf("%d", &newEvent.month);
    printf("Year: ");
    scanf("%d", &newEvent.year);
    printf("Description: ");
    getchar();
    fgets(newEvent.description, sizeof(newEvent.description), stdin);

    calendar->events[calendar->count] = newEvent;
    calendar->count++;

    printf("Event added successfully.\n");
}

void displayEvents(Calendar *calendar)
{
    printf("Events:\n");
    for (int i = 0; i < calendar->count; i++)
    {
        Event event = calendar->events[i];
        printf("%d/%d/%d: %s", event.day, event.month, event.year, event.description);
    }
}

void projectHeader(const char *message)
{
    system("cls");
    printf("\n");
    printf("\n\t\t\t***********************************************");
    printf("\n\t\t\t***********************************************");
    printf("\n\t\t\t**           Event Management App            **");
    printf("\n\t\t\t**                                           **");
    printf("\n\t\t\t***********************************************");
    printf("\n\t\t\t***********************************************");
    printf("\n\t\t\t\t\t%s", message);
    printf("\n\t\t\t-----------------------------------------------");
}

void submittedBy()
{
    projectHeader("Submitted By Menu");
    printf("\n\n\n");
    printf("\n\t\t\t    	=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
    printf("\n\t\t\t    	=      	Name  	ID     	               =");
    printf("\n\t\t\t    	=**************************************=");
    printf("\n\t\t\t    	=       Anik    ID 0242310005101779    =");
    printf("\n\t\t\t    	=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
    printf("\n\n\n\t\t\t Enter any key to continue.....");
    getchar();
    getchar();
}

void submittedTo()
{
    projectHeader("Submitted To Menu");
    printf("\n\n\n");
    printf("\n\t\t\t    	=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t    	=   Abdullah Al Mamun(AAM)        =");
    printf("\n\t\t\t    	=*********************************=");
    printf("\n\t\t\t    	=	Lecturer      	          =");
    printf("\n\t\t\t    	=	Dept. of CSE             =");
    printf("\n\t\t\t    	=	DIU                       =");
    printf("\n\t\t\t    	=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\n\n\t\t\t Enter any key to continue.....");
    getchar();
    getchar();
}

void selectOption()
{
    system("color 0e");
    projectHeader("MAIN MENU");
    printf("\n\n\n\t\t\t1. Submitted By");
    printf("\n\t\t\t2. Submitted To");
    printf("\n\t\t\t3. Events");
    printf("\n\n\n\t\t\tEnter choice => ");
    int choice1;
    scanf("%d", &choice1);
    getchar();
    switch (choice1)
    {
    case 1:
        submittedBy();
        break;
    case 2:
        submittedTo();
        break;
    case 3:
        printf("This is the Events section.\n");

        break;
    default:
        printf("\n\n\n\t\t\tWRONG CHOICE !!! Try again...");
        getchar();
        getchar();
    }
}

int main()
{
    system("color 4e");
    Calendar calendar;
    calendar.count = 0;

    while (1)
    {
        selectOption();

        printf("\n\t\t\t0. Exit");
        printf("\n\t\t\t1. Continue");
        printf("\n\t\t\t2. Events");
        printf("\n\n\n\t\t\tEnter choice => ");
        int choice2;
        scanf("%d", &choice2);
        getchar();
        if (choice2 == 0)
        {
            printf("\n\n\n\t\t\t\tThank you!!!\n\n\n\n\n");
            break;
        }
        else if (choice2 == 1)
        {
            selectOption();
        }
        else if (choice2 == 2)
        {
            int choice;
            do
            {
                printf("\nSystem\n");
                printf("1. Add Event\n");
                printf("2. Display Events\n");
                printf("3. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);
                getchar();

                switch (choice)
                {
                case 1:
                    addEvent(&calendar);
                    break;
                case 2:
                    displayEvents(&calendar);
                    break;
                case 3:
                    printf("Exiting the application.\n");
                    break;
                default:
                    printf("Invalid choice. Please try again.\n");
                }
            }
            while (choice != 3);
        }
    }

    return 0;
}