int highscore(int);
int highscore(int temp)
{
 int high;
 FILE *fp;
 fp=fopen("high","r+b");
 if(fp==NULL)
  {
   fp=fopen("high","wb");
   fwrite(&temp,sizeof(int),1,fp);
   fclose(fp);
   return temp;
  }
 fread(&high,sizeof(int),1,fp);
 if(high>=temp)
 return high;
 rewind(fp);
 fwrite(&temp,sizeof(int),1,fp);
 fclose(fp);
 return(temp);
}

