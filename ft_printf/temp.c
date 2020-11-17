int main()
{
	ft_printf("this %s is %s", "", "hello");
}



/*

int	main(void)
{
	
	int ret;
	char *str;

	ft_printf("1.%*c.\n",12, 'c');
    printf("\n");
    ft_printf("2.%*c.\n",-12, 'c');
    printf("\n");
    ft_printf("3.%-12c.\n", 'c');
    printf("\n");
    ft_printf("4.%.c.\n", 'c');
    printf("\n");
    ft_printf("5.%0c.\n", 'c');
    printf("\n");
    ft_printf("6.%*c.\n",0, 'c');
    printf("\n");
    ft_printf("7.%-0c.\n", 'c');
    printf("\n");
    ft_printf("8.%-12c.\n", 'c');
    printf("\n");

	printf("1.%*c.\n",12, 'c');
    printf("\n");
    printf("2.%*c.\n",-12, 'c');
    printf("\n");
    printf("3.%-12c.\n", 'c');
    printf("\n");
    printf("4.%.c.\n", 'c');
    printf("\n");
    printf("5.%0c.\n", 'c');
    printf("\n");
    printf("6.%*c.\n",0, 'c');
    printf("\n");
    printf("7.%-0c.\n", 'c');
    printf("\n");
    printf("8.%-12c.\n", 'c');
    printf("\n");



	ft_printf(".%.c.", 'c');
	ft_printf("\n");
	printf(".%c.", 'c');

	ret = printf(".%+-5d.",0);
	printf("\n%d\n", ret);
	ret = ft_printf(".%+-5d.",0);
	printf("\n%d\n", ret);
	printf("\n");
	g_count = 0;

	ret = printf(".%+-5d.",-7);
	printf("\n%d\n", ret);
	ret = ft_printf(".%+-5d.",-7);
	printf("\n%d\n", ret);
	printf("\n");
	g_count = 0;

	ret = printf("%+05d",0);
	printf("\n%d\n", ret);
	ret = ft_printf("%+05d",0);
	printf("\n%d\n", ret);
	printf("\n");
	g_count = 0;

	ret = printf("%+05d",-7);
	printf("\n%d\n", ret);
	ret = ft_printf("%+05d",-7);
	printf("\n%d\n", ret);
	printf("\n");
	g_count = 0;

	ret = printf("%+05d",1560133635);
	printf("\n%d\n", ret);
	ret = ft_printf("%+05d",1560133635);
	printf("\n%d\n", ret);
	printf("\n");
	g_count = 0;

	ret = printf("%+05d",-2035065302);
	printf("\n%d\n", ret);
	ret = ft_printf("%+05d",-2035065302);
	printf("\n%d\n", ret);
	printf("\n");
	g_count = 0;
	return (0);
}

*/