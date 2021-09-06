void box()
{
  clrscr();
  for(int lc=2; lc<24; lc++)
  {
  gotoxy(1,lc); cout<<(char)219;
  delay(10);
  }

  for(int br=2; br<60; br++)
  {
   gotoxy(br,23); cout<<(char)219;
   delay(10);
  }

  for(int rc=23; rc>1; rc--)
  {
   gotoxy(60,rc); cout<<(char)219;
   delay(10);
   }

  for(int tr=59; tr>1; tr--)
  {
   gotoxy(tr,2); cout<<(char)219;
   delay(10);
  }


  }