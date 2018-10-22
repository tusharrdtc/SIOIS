/*char a[1];
a[0]=
/*char on[33]="7e3b55c4b16ff4e73b9f7092328921b6";
char of[33]="c78c992ebd0b4fb06b5cd2d70ef9454b";*/
char t30[33]="8f6658a306d37b2a292bf76051a05727";
char t29[33]="c6783db30f0614d95c0b45a72449e5a5";
char t28[33]="d56606c2aa4ab40c8d11419a773b4d7f";
char t27[33]="66ab5000c4d2d97a060f615eb3dd8526";
char t26[33]="009f825d944354a99feac1463872ee62";
char t25[33]="7fa7408907cee176a2e6fcfeda086bdb";
char t24[33]="3876f5b0d0a50c41f31ab79c9a3747db";
char t23[33]="8acd79510da2ce75daf842574b070e1e";
char t22[33]="33665d65dad0f26c8318bb616647d622";
char t21[33]="08c9b86923119eebd461e3bb78bca707";
char t20[33]="f16b4398c8c8388cefaa32aa198bab7e";
char t19[33]="c3fa5a9cef2830841765089f512a84b9";
char t18[33]="844abd713cba6e8c21ceac12dea0ca90";
char t17[33]="2603821981f4d5e8aaee9b741de45d2e";
char t16[33]="2603821981f4d5e8aaee9b741de45d2e";
unsigned char *p = (unsigned char *)&t30;           
 void md5()
{
    delay(1000);
    unsigned char* hash=MD5::make_hash(s);
    char *md5str = MD5::make_digest(hash, 16);
    free(hash);
    Serial.println("");
    Serial.print("recorded array is:  ");
    Serial.print(md5str);
    Serial.println("");
    /*if(strcmp(md5str,on) == 0)
    {
      Serial.print(on);
      Serial.println("");
      Serial.print("current status is:  ");
      Serial.println("on");
      Serial.println("");
     /*Serial.println(t30);
     int len1 = strlen(t30);
     Serial.println(len1);
     Serial.println("matched");
    }
    if(strcmp(md5str,of) == 0)
    {
      Serial.print(of);
      Serial.println("");
      Serial.print("current status is:  ");
      Serial.println("OFF");
      Serial.println("");
    }*/
    if(strcmp(md5str,t30) == 0)
    {
      Serial.print("stored array is:  ");
      Serial.print(t30);
      Serial.println("");
      Serial.print("current temp is:  ");
      Serial.print("30");
      Serial.println("");
    }
    if(strcmp(md5str,t29) == 0)
    {
      Serial.print(t29);
      Serial.println("");
      Serial.print("current temp is:  ");
      Serial.print("29");
      Serial.println("");
     }
    if(strcmp(md5str,t28) == 0)
    {
      Serial.print("stored array is:  ");
       Serial.print(t28);
      Serial.println("");
      Serial.print("current temp is:  ");
      Serial.print("28");
      Serial.println("");
     }
    if(strcmp(md5str,t27) == 0)
    {
      Serial.print("stored array is:  ");
      Serial.print(t27);
      Serial.println("");
      Serial.print("current temp is:  ");
      Serial.print("27");
      Serial.println("");
     }
    /*if(strcmp(md5str,t26) == 0)
    {
      Serial.print(t26);
      Serial.println("");
      Serial.print("current temp is:  ");
      Serial.print("26");
      Serial.println("");
     }*/
    if(strcmp(md5str,t25) == 0)
    {
      Serial.print("stored array is:  ");
      Serial.print(t25);
      Serial.println("");
      Serial.print("current temp is:  ");
      Serial.print("25");
      Serial.println("");
     }
    if(strcmp(md5str,t24) == 0)
    {
      Serial.print("stored array is:  ");
      Serial.print(t24);
      Serial.println("");
      Serial.print("current temp is:  ");
      Serial.print("24");
      Serial.println("");
    }
    if(strcmp(md5str,t23) == 0)
    {
      Serial.print("stored array is:  ");
      Serial.print(t23);
      Serial.println("");
      Serial.print("current temp is:  ");
      Serial.print("23");
     }
    /*if(strcmp(md5str,t22) == 0)
    {
      Serial.print(t22);
      Serial.println("");
      Serial.print("current temp is:  ");
      Serial.print("22");
      Serial.println("");
     }
    if(strcmp(md5str,t21) == 0)
    {
      Serial.println("");
      Serial.print("current temp is:  ");
      Serial.print("21");
      Serial.println("");
     }
    if(strcmp(md5str,t20) == 0)
    {
      Serial.println("");
      Serial.print("current temp is:  ");
      Serial.print("20");
     }
    if(strcmp(md5str,t19) == 0)
    {
      Serial.println("");
      Serial.print("current temp is:  ");
      Serial.print("19");
      Serial.println("");
     }
    if(strcmp(md5str,t18) == 0)
    {
      Serial.println("");
      Serial.print("current temp is:  ");
      Serial.print("18");
      Serial.println("");
     }
    if(strcmp(md5str,t17) == 0)
    {
      Serial.println("");
      Serial.print("current temp is:  ");
      Serial.print("17");
      Serial.println("");
     }
    if(strcmp(md5str,t16) == 0)
    {
      Serial.println("");
      Serial.print("current temp is:  ");
      Serial.print("16");
      Serial.println("");
     }*/
     free(md5str);
}


