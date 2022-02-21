#include<stdio.h>
int cube(int a)
{
	return (a * a * a);
}
int cuboid(int a, int b, int c)
{
	return (a * b * c);
}
float sphere(int a)
{
	float volume = (3.14 * a * a * a) * (4 / 3);
	return volume;
}
int main()
{
	printf("select shape for voulme\n");
	printf("c for cube\nb for cuboid\ns for sphere\n");
	char choice;
	scanf("%c", &choice);
	int a, b, c;
	switch (choice)
	{
	case 'c':
		printf("enter dimensions\n");
		scanf("%d", &a);
		printf("volume : %d", cube(a));
		break;
	case 'b':
		printf("enter dimensions\n");
		scanf("%d%d%d", &a, &b, &c);
		printf("volume : %d", cuboid(a, b, c));
		break;
	case 's':
		printf("enter radius\n");
		scanf("%d", &a);
		printf("volume : %f", sphere(a));
		break;
	default:
		printf("select a valid choice");

	}
	return 0;
}