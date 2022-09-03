#include<stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <dos.h>

char password[10] = {"pass"};
char catagories[][15] = {"New Member", "Coach", "Staff"};
int s;
char findstaff;
FILE *fp, *ft, *fs;

struct staff
{
	int id;
	char stname[20];
	char name[20];
	char Address[20];
	char membersince[10];
	int contact;
	int count;
	char *cat;
};
struct staff a;


void mainmenu(void);

void addstaff(void);

void deletestaff(void);

void editstaff(void);

void searchstaff(void);

void viewstaff(void);

int getdata();

void Password();


// the main function
int main(){
    Password();
    getch();
	return 0;
}


void mainmenu()
{
	printf("\n\n\xdb\xdb\xdb\xdb\xdb\xdb  MAIN MENU \xdb\xdb\xdb\xdb\xdb\xdb\n");
	printf("<1> Add Members\n");
	printf("<2> Remove Members\n");
	printf("<3> Search Members\n");
	printf("<4> View Member's list\n");
	printf("<5> Edit Members Record\n");
	printf("<6> Close Application\n");
	printf("Enter your choice:");

	switch (getch())
	{
	case '1':
		addstaff();
		break;

	case '2':
		deletestaff();
		break;

	case '3':
		searchstaff();
		break;

	case '4':
		viewstaff();
		break;

	case '5':
		editstaff();
		break;

	case '6':
	{
		printf("\tGYM Management System\n");
		printf("\tProject in C\n");
		printf("\tis brought to you by\n");
		printf("\tAzizur Rahman Ankon\n");
		exit(0);
	}

	default:
	{
		printf("\aWrong Entry!!Please re-entered correct option\n");
		if (getch())
			mainmenu();
	}
	}
}


int checkid(int t)
{
	rewind(fp);

	while (fread(&a, sizeof(a), 1, fp) == 1)
		if (a.id == t)
			return 0;

	return 1;
}


int getdata()
{
	int t;
	printf("\n\nEnter the Information Below Category:");
	printf("%s", catagories[s - 1]);
	printf("\nID:\t");
	scanf("%d", &t);
	if (checkid(t) == 0)
	{
		printf("\n\n\aThe id already exists\a\n\n");
		getch();
		mainmenu();
		return 0;
	}

	a.id = t;
	printf("\nName:");
	scanf("%s", a.name);
	printf("\nAddress:");
	scanf("%s", a.Address);
	printf("\nContact:");
	scanf("%d", &a.contact);
	printf("\nMember Since:");
	scanf("%s", &a.membersince);
	return 1;
}


void addstaff()
{
	int i;
	printf("\n\n\xdb\xdb\xdb\xdb\xdb\xdb  SELECT CATEGORIES \xdb\xdb\xdb\xdb\xdb\xdb\n");
	printf("<1> New Member\n");
	printf("<2> Coach\n");
	printf("<3> Staff\n");
	printf("<4> Back to main menu\n\n");
	printf("Enter your choice:");

	scanf("%d", &s);

	if (s == 4)
		mainmenu();


	fp = fopen("stf.dat", "ab+"); //Open a binary file in append mode for writing at the end of the file. The fopen() function creates the file if it does not exist.

	if (getdata() == 1)
	{
		a.cat = catagories[s - 1];
		fseek(fp, 0, SEEK_END);
		fwrite(&a, sizeof(a), 1, fp);
		fclose(fp);
		printf("\nThe record is sucessfully saved\n\n");
		printf("Save any more?(Y / N):");
		if (getch() == 'n')
			mainmenu();

		else
			addstaff();

	}
}


void deletestaff()
{
	int d;
	char another = 'y';
	while (another == 'y')
	{
		printf("\n\nEnter the ID to  remove:");
		scanf("%d", &d);
		fp = fopen("stf.dat", "rb+");
		rewind(fp);

		while (fread(&a, sizeof(a), 1, fp) == 1)
		{
			if (a.id == d)
			{
				printf("\n\nThe record is available...\n");
				printf("\nName is %s", a.name);
				findstaff = 't';
			}
		}

		if (findstaff != 't')
		{
			printf("\nNo record is found modify the search");
			if (getch())
				mainmenu();
		}

		if (findstaff == 't')
		{
			printf("\nDo you want to delete it?(Y/N):");
			if (getch() == 'y')
			{
				ft = fopen("test.dat", "wb+");
				rewind(fp);
				while (fread(&a, sizeof(a), 1, fp) == 1)
				{
					if (a.id != d)
					{
						fseek(ft, 0, SEEK_CUR);
						fwrite(&a, sizeof(a), 1, ft);
					}
				}

				fclose(ft);
				fclose(fp);
				remove("stf.dat");
				rename("test.dat", "stf.dat");
				fp = fopen("stf.dat", "rb+");

				if (findstaff == 't')
				{
					printf("\nThe record is sucessfully deleted");
					printf("\n\tDelete another record?(Y/N)");
				}
			}

			else
				mainmenu();

			fflush(stdin);
			another = getch();
		}
	}
	mainmenu();
}


void searchstaff()
{
	int d;
	printf("\n\nSearch Member:");
	printf("\n1. Search By ID");
	printf("\n2. Search By Name");
	printf("\nEnter Your Choice");

	fp = fopen("stf.dat", "rb+");

	rewind(fp);

	switch (getch())
	{
	case '1':
	{
		printf("\n\nSearch By Id........\n");
		printf("\n\nEnter the id:");
		scanf("%d", &d);

		while (fread(&a, sizeof(a), 1, fp) == 1)
		{
			if (a.id == d)
			{
				printf("\nThe Record is available\n");
				printf("\nID:%d", a.id);
				printf("\nCategory:%s", a.cat);
				printf("\nName:%s", a.name);
				printf("\nAddress:%s ", a.Address);
				printf("\nContact:%i ", a.contact);
				printf("\nMember Since:%s", a.membersince);
				findstaff = 't';
			}
		}

		if (findstaff != 't')
		{
			printf("\n\aNo Record Found");
		}

		printf("\nTry another search?(Y/N)");

		if (getch() == 'y')
			searchstaff();
		else
			mainmenu();
		break;
	}

	case '2':
	{
		char s[15];
		printf("Search Record By Name.......");
		printf("Enter the Name:");
		int d = 0;

		while (fread(&a, sizeof(a), 1, fp) == 1)
		{
			if (strcmp(a.name, (s)) == 0)
			{
				printf("ID:%d\n", a.id);
				printf("Name:%s\n", a.name);
				printf("Address:%s\n", a.Address);
				printf("Contact:%i\n", a.contact);
				printf("Member Since:%s\n", a.membersince);
				getch();
				d ++;
			}
		}
		if (d == 0)
			printf("\aNo Record Found");

		printf("Try another search?(Y/N)");

		if (getch() == 'y')
			searchstaff();
		else
			mainmenu();
	
    	break;
	}

	default:
		getch();
    	searchstaff();
	}

	fclose(fp);
}


void viewstaff(void)
{
	printf("\n\nMember List\n\n");
	printf("\n CATEGORY === ID ==== NAME ======== ADDRESS ===== CONTACT ===== MEMBER SINCE ");

	fp = fopen("stf.dat", "rb");

	while (fread(&a, sizeof(a), 1, fp) == 1)
	{
		printf("\n%s", a.cat);
		printf("\n%d", a.id);
		printf("\n%s", a.name);
		printf("\n%s", a.Address);
		printf("\n%i", a.contact);
		printf("\n%s", a.membersince);
		printf("\n\n");
	}

	fclose(fp);
	mainmenu();
}


void editstaff(void)
{
	int c = 0;
	int d, e;
	printf("\xdb\xdb\xdb\xdb\xdb\xdb Edit Member's Record \xdb\xdb\xdb\xdb\xdb\xdb");
	char another = 'y';

    while (another == 'y')
	{
		printf("\n\nEnter Id to be edited:");
		scanf("%d", &d);
		fp = fopen("stf.dat", "rb+");

		while (fread(&a, sizeof(a), 1, fp) == 1)
		{
			if (checkid(d) == 0)
			{
				printf("\nThis Member is available");
				printf("\nThe ID:%d", a.id);
				printf("\nEnter new name:");
				scanf("%s", a.name);
				printf("\nEnter new Address:");
				scanf("%s", a.Address);
				printf("\nEnter new Contact:");
				scanf("%i", &a.contact);
				printf("\nEnter New Membership date:");
	    		scanf("%s", &a.membersince);
				printf("\nThe record is modified");
				fseek(fp, ftell(fp) - sizeof(a), 0);
				fwrite(&a, sizeof(a), 1, fp);
				fclose(fp);
				c = 1;
			}

			if (c == 0)
			{
				printf("\nNo record found");
			}
		}
		printf("\nModify another Record?(Y/N)");
		fflush(stdin);
		another = getch();
	}
	mainmenu();
}


void Password(void)
{
	char d[25] = "Password Protected";
	char ch, pass[10];
	int i = 0, j;
	printf("\n\n\xdb\xdb\xdb\xdb\xdb\xdb WELCOME To GYM Management System \xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
	printf("Enter Password:");

	while (ch != 13)
	{
    	ch = getch();
		if (ch != 13 && ch != 8)
		{
			putch('*');
			pass[i] = ch;
			i++;
		}
	}

	pass[i] = '\0';

	if (strcmp(pass, password) == 0)
	{
		printf("\nPassword matched!!");
		printf("\nPress any key to countinue.....");
		getch();
		mainmenu();
	}
	else
	{
		printf("\nIncorrect Password!!!\n Try again...\n\n");
		getch();
		Password();
	}
}