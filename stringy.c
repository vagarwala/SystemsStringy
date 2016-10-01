#include <stdio.h>
#include <string.h>

int my_strlen(char *string){
	int length = 0;
	while (*string != 0){
		length++;
		string++;
	}
	return length;
}

char * my_strncpy(char *str1, char *str2, int num){
	while (num && *str2){
		*str1 = *str2;
		str1++;
		str2++;
		num--;
	}
	return str1;
}

char * my_strcat(char *str1, char *str2){
	char i = strlen(str1);
	char j = 0;
	while (str2[j]){
		str1[i] = str2[0];
	    str2++;
	    i++;
	    j++;
	}
	return str1;
}

int my_strcmp( char *str1, char *str2 ) {
	while ( *str1 != 0 || *str2 != 0 ) {
    	if ( *str1 != *str2 )
        	return *str1 - *str2;
    	str1++;
    	str2++;
    }
    return 0;
}

char * my_strchr(char *str, char chr){
	int ind = 0;
	while(str[ind]){
		if (str[ind] == chr)
			return str + ind;
		ind++;
	}
	return 0;
}


int main(){
	printf("my_strlen\n\n");
	printf("happy: %lu \n", strlen("happy"));
	printf("should be 5: %d \n", my_strlen("happy"));
	printf("'': %lu \n", strlen(""));
	printf("should be 0: %d \n", my_strlen(""));
	printf("confirmation: %lu \n", strlen("confirmation"));
	printf("should be 12: %d \n", my_strlen("confirmation"));

	printf("--------------------------- \n\n");

	printf("my_strncpy:\n\n");
	char str1[50] = "happy";
	char str2[] = "confirmation";
	strncpy(str1, str2, 4);
	printf("hello + confirmation, 4 --> %s \n", str1);
	strcpy(str1, "happy");
	strcpy(str2, "confirmation");
	my_strncpy(str1, str2, 4);
	printf("should be confy: %s \n", str1);

	printf("--------------------------- \n\n");

	printf("my_strcat: \n\n");
	strcpy(str1, "happy");
	strcat(str1, str2);
	printf("happy + confirmation = %s \n", str1);
	strcpy(str1, "hello");
	my_strcat(str1, str2);
	printf("should be happyconfirmation: %s\n", str1);

	printf("--------------------------- \n\n");

	printf("my_strcmp: \n\n");
	strcpy(str1, "diagonal");
	strcpy(str2, "dialysis");
	char str3[] = "diagnosis";
	printf("diagonal and diagonal: %d \n", strcmp(str1, str1));
	printf("should be 0: %d \n", my_strcmp(str1, str1));
	printf("diagonal and diagnosis: %d \n", strcmp(str1, str3));
	printf("should be 1: %d \n", my_strcmp(str1, str3));
	printf("diagnosis and dialysis: %d \n", strcmp(str3, str2));
	printf("should be -5: %d \n", my_strcmp(str3, str2));

	printf("--------------------------- \n\n");

	printf("my_strchr: \n\n");
	strcpy(str1, "ababababababnabab");
	char thing = 'n';
	printf("%s \n", strchr(str1, thing));
	printf("should be nabab: %s", my_strchr(str1, thing));

}