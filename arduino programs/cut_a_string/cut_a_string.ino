char str[]={'n','o',' ','h','e','l','l','o',' ','w','o','r','l','d'};
void setup() 
{
  Serial.begin(9600);
  

}

void loop()
{
 
 int str_cut(char *str, int begin, int len);
 delay(1000);
}
int str_cut(char *str, int begin, int len)
{
    int l = strlen(str);

    if (len < 0) len = l - begin;
    if (begin + len > l) len = l - begin;
    memmove(str + begin, str + begin + len, l - len + 1);
    Serial.println(len);
    //return len;
}
