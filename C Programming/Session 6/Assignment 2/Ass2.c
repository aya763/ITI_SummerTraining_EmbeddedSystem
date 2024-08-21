

#include <stdio.h>
#include <string.h>


struct Employee {
    char name[50];
    int id;
    union {
        float salary;
        char department[50];
    } info;
    int type; // 0 for salary, 1 for department
};


void addEmployee(struct Employee employees[], int *count) 
{
    if (*count >= 100) {
        printf("Employee record is full. Cannot add more employees.\n");
        return;
    }

    struct Employee newEmployee;
    printf("Enter employee name: ");
    scanf("%s", newEmployee.name);
    printf("Enter employee ID: ");
    scanf("%d", &newEmployee.id);
    printf("Choose type (0 for salary, 1 for department): ");
    scanf("%d", &newEmployee.type);

    if (newEmployee.type == 0) 
	{
        printf("Enter salary: ");
        scanf("%f", &newEmployee.info.salary);
    } 
	else 
	{
        printf("Enter department: ");
        scanf("%s", newEmployee.info.department);
    }

    employees[*count] = newEmployee;
    (*count)++;
}


void displayEmployees(struct Employee employees[], int count) 
{
	if(count>0)
	{
		printf("Employee Information:\n");
		for (int i = 0; i < count; i++) 
		{
			printf("Name: %s, ID: %d, ", employees[i].name, employees[i].id);
			if (employees[i].type == 0) 
			{
				printf("Salary: %.2f\n", employees[i].info.salary);
			} 
			else 
			{
				printf("Department: %s\n", employees[i].info.department);
			}
		}
	}
	else 
	{
		printf("No employee found\n");
	}
    
}


void findEmployee(struct Employee employees[], int count, int id) 
{
    for (int i = 0; i < count; i++) 
	{
        if (employees[i].id == id) 
		{
            printf("Employee found:\n");
            printf("Name: %s, ID: %d, ", employees[i].name, employees[i].id);
            if (employees[i].type == 0) 
			{
                printf("Salary: %.2f\n", employees[i].info.salary);
            } 
			else 
			{
                printf("Department: %s\n", employees[i].info.department);
            }
            return;
        }
    }
    printf("Employee with ID %d not found.\n", id);
}


void updateSalary(struct Employee employees[], int count, int id, float newSalary) 
{
    for (int i = 0; i < count; i++) 
	{
        if (employees[i].id == id && employees[i].type == 0) 
		{
            employees[i].info.salary = newSalary;
            printf("Salary updated successfully.\n");
            return;
        }
    }
    printf("Employee with ID %d not found or not of type salary.\n", id);
}


void listByDepartment(struct Employee employees[], int count, const char *department) 
{
	if(count>0)
	{
		int found=0;
		printf("Employees in department %s:\n", department);
		for (int i = 0; i < count; i++) 
		{
			if (employees[i].type == 1 && strcmp(employees[i].info.department, department) == 0) 
			{
				printf("Name: %s, ID: %d\n", employees[i].name, employees[i].id);
				found=1;
			}
		}
		if(!found)
		{
			printf("There is no employee in this department.\n");
		}
	}
	else 
	{
		printf("Empty employees List\n");
	}
	
	
}

int main() {
    struct Employee employees[100];
    int count = 0,choice,id; 
	float salary;
	char department[50];
	
	while(1)
	{
		printf("\n\n1.Add employee\n2.Display employees\n3.find employee\n4.update salary of employee\n5.List by department\n");
	
		printf("Enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				addEmployee(employees, &count);
				break;
			case 2:
				displayEmployees(employees, count);
				break;
			case 3:
				printf("Enter ID of employee you want to found: ");
				scanf("%d",&id);
				findEmployee(employees, count, id);
				break;
			case 4:
				printf("Enter ID of employee you want to update his salary: ");
				scanf("%d",&id);
				printf("Enter new salary: ");
				scanf("%f",&salary);
				updateSalary(employees, count, id, salary);
				break;
			case 5:
				printf("Enter Department you want to list its employees: ");
				gets(department);
				gets(department);
				listByDepartment(employees, count, department);
				break;
			default:
				printf("Wrong choice\n\n");
		}
	}
	
	

    /* // Example usage:
    addEmployee(employees, &count);
    addEmployee(employees, &count);
    displayEmployees(employees, count);
    findEmployee(employees, count, 1001);
    updateSalary(employees, count, 1001, 55000.0);
    listByDepartment(employees, count, "HR"); */

    return 0;
}
