#include <stdio.h>
#include <string.h>

void prints(char *s);
void reversew(char *s);

int main(int argc, char const *argv[])
{
	char str[] = "No,description,website,or,topics,provided";
	prints(str);
	reversew(str);
	prints(str);

	return 0;
}

void prints(char *s)
{
	for ( ; *s != '\0'; s++)
	{
		putchar(*s);
	}
	putchar('\n');
}

void reversew(char *s)
{
	int slen = strlen(s);
    
    // reverse all string
    for (int i = 0; i < slen/2; i++) {
        char temp = s [i];
        s[i] = s [slen-i-1]; 
        s [slen-i-1] = temp;        
    }

    // reverse each word
    for (int pos = 0, wlen = 0; pos <= slen; pos++, wlen++) {
    	if (s[pos] == ',' || s[pos] == '\0') {  
    	    for (int i = 0; i < wlen/2; i++) {
    	        char temp = s [pos - i - 1]; 
    	        s [pos - i - 1] = s[pos - wlen + i];
    	        s [pos - wlen + i] = temp;
    	    }
    	    s[pos] = ' ';  
    	    pos++;
    	    wlen = 0;            
    	}
    }
}