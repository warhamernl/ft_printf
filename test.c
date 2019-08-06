#include <printf.h>

int     main(void)
{
 	printf("The color: %s\n", "blue");
	printf("First number: %d\n", 12345);
	printf("Second number: %04d\n", 25);
	printf("Third number: %i\n", 1234);
	printf("Float number: %3.2f\n", 3.14159);
	printf("Hexadecimal: %x\n", 255);
	printf("Octal: %o\n", 255);
	printf("Unsigned value: %u\n", 150);
	printf("Just print the percentage sign %%\n");

    printf(":%s:\n", "Hello, world!");
	printf(":%15s:\n", "Hello, world!");
	printf(":%.10s:\n", "Hello, world!");
	printf(":%-10s:\n", "Hello, world!");
	printf(":%-15s:\n", "Hello, world!");
	printf(":%.15s:\n", "Hello, world!");
	printf(":%15.10s:\n", "Hello, world!");
	printf(":%-15.10s:\n", "Hello, world!");

    printf("%                 5d\n", 10);
    printf("%    .15     d   \n", 10);
    printf("%d\n", 10);
}

/*
 #include <stddef.h>
 #include <stdio.h>
 
 typedef enum    e_desc {
 E_FLOAT = 0,
 E_INT = 1,
 E_STRING = 2,
 E_INVALID = 3,
 }               t_desc;
 
 typedef struct  s_pair {
 char    key;
 t_desc  desc;
 }               t_pair;
 
 static const t_pair g_lookup_array[] = {
 { 'd', E_INT },
 { 's', E_STRING },
 { 'f', E_FLOAT },
 };
 
 
 t_desc find_descriptor(char c)
 {
 size_t i = 0;
 size_t length = sizeof(g_lookup_array) / sizeof(t_pair); // 3
 while (i < length)
 {
 t_pair pair = g_lookup_array[i];
 if (c == pair.key)
 {
 return (pair.desc);
 }
 i++;
 }
 return (E_INVALID);
 }
 
 int main(void)
 {
 char *string = "%d";
 
 char c = string[1]; // d
 
 t_desc desc = find_descriptor(c);
 printf("%d\n", desc); // E_INT = 1
 
 char buffer[1024] = {};
 
 
 // writer->write("Hello, World", 5);
 
 
 return (0);
 }


*/
/*
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
// write

typedef struct	s_writer
{
    void	(*write)(struct s_writer*, char*, size_t);
    
    size_t	written;
    
    void	*state;
}				t_writer;

typedef struct	s_writer_alloc_state
{
    char	**str_ptr;
    size_t	len;
    size_t	cap;
}				t_writer_alloc_state;

void	write_write(t_writer *writer, char *str, size_t len)
{
    writer->write(writer, str, len);
}

void	writer_out_write(struct s_writer *self, char *str, size_t len)
{
    self->written += len;
    write(1, str, len);
}

void	writer_alloc_write(t_writer *self, char *str, size_t length)
{
    t_writer_alloc_state	*state;
    size_t					new_cap;
    
    state = (t_writer_alloc_state*)self->state;
    if (self->failed)
        return ;
    if (state->len + length + 1 > state->cap)
    {
        new_cap = vector_cap_for_length(state->len + length + 1);
        *state->str_ptr = std_realloc(*state->str_ptr, state->cap, new_cap);
        state->cap = new_cap;
        if (*state->str_ptr == NULL)
        {
            self->failed = 1;
            return ;
        }
    }
    if (std_memcpy(*state->str_ptr + state->len, str, length) == NULL)
    {
        self->failed = 1;
        return ;
    }
    state->len += length;
    (*state->str_ptr)[state->len] = '\0';
    self->written += length;
}

int main(void)
{
    t_writer	writer;
    t_writer_alloc_state	alloc;
    
    char *line;
    
    line = malloc(1);
    line[0] = '\0';
    
    memset(&alloc, 0, sizeof(t_writer_alloc_state));
    alloc.str_ptr = &line;
    
    writer.write = writer_alloc_write;
    writer.written = 0;
    
    write_write(&writer, "Hello, world", 5);
    
    printf("\n%zu written\n", writer.written);
    
    return (0);
}


/*
