 #include <stddef.h>
 #include <stdio.h>
 
 typedef enum    e_desc {
 E_CHAR             = 0,
 E_STRING           = 1,
 E_VOID_POINTER     = 2,
 E_INT              = 3,
 E_IINT             = 4,
 E_OCTAL            = 5,
 E_HEX              = 6,
 E_UHEX             = 7,
 E_FLOAT            = 8,
 E_INVALID          = -1
 }               t_desc;
 
 typedef struct  s_pair {
 char    key;
 t_desc  desc;
 }               t_pair;
 
 static const t_pair g_lookup_array[] = {
 { 'c', E_CHAR },
 { 's', E_STRING },
 { 'p', E_VOID_POINTER },
 { 'i', E_IINT },
 { 'd', E_INT },
 { 'o', E_OCTAL },
 { 'x', E_HEX },
 { 'X', E_UHEX },
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
 
 
 return (0);
 }

