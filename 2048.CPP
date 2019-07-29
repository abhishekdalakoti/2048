
#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <string.h>
#include <dos.h>
#include <stdlib.h>

//##########################################INITIALISE VALUES###############################################

int m,n,choice,p=0;
int r[4];
int ra[5];
int ro[3];
int check=0;
int ran,end;
int score=0,highscore,highscoree,highscored;

void counter();
void over();
void win();

// ########################################### RANDOM #######################################################

int random()
{
 int i;
 i= rand() % (ran + 1);
 return i;
}

// ########################################## PRINTING FUNCTION #############################################

/*level medium(4*4)*/
int printer(int c[4][4])
{
 int gd = DETECT, gm;
 int e=0;
 int i,j,k, midx, midy, count,minx, miny;

 initgraph(&gd, &gm, "c:\\TURBOC3\\BGI");
 midx = getmaxx()/2;
 midy = getmaxy()/2;
 /* get mid positions in x and y-axis */

 char string[100];

 /*setting formatting styles*/
 setcolor(LIGHTCYAN);
 settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 1);
 settextjustify(CENTER_TEXT, CENTER_TEXT);
 sprintf(string,"HIGHSCORE: %d\tSCORE: %d\n",highscore,score);
 outtextxy(150,50,string);


 for (j = 0; j < 4; j++)
 for (k = 0; k < 4; k++)
 {
   /* draws the grid board */
   setcolor(YELLOW);
   rectangle(midx - 120+60*j, midy - 120+60*k, midx - 60+60*j, midy -60+60*k);

   /* place the counter inside rectangle */
   setcolor(LIGHTCYAN);
   settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 1);
   settextjustify(CENTER_TEXT, CENTER_TEXT);

   if(c[j][k]==2048)
     e=2;
   if (c[j][k]!=0)
     sprintf(string,"%d ",c[j][k]);
   else
     sprintf(string,"   ");

   outtextxy(midx-90+60*k, midy-90+60*j, string);
 }

 getch();
 closegraph();
 return e;

 }

/*level difficult(3*3)*/
int printerd(int c[3][3])
{
 int gd = DETECT, gm;
 int e=0;
 int i,j,k, midx, midy, count,minx, miny;

 initgraph(&gd, &gm, "c:\\TURBOC3\\BGI");
 midx = getmaxx()/2;
 midy = getmaxy()/2;
 /* get mid positions in x and y-axis */

 char string[100];

 setcolor(LIGHTCYAN);
 settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 1);
 settextjustify(CENTER_TEXT, CENTER_TEXT);
 sprintf(string,"HIGHSCORE: %d\tSCORE: %d\n",highscored,score);
 outtextxy(150,50, string);


 for (j = 0; j < 3; j++)
 for (k = 0; k < 3; k++)
 {
   /* draws the grid board */
   setcolor(YELLOW);
   rectangle(midx - 90+60*j, midy - 90+60*k, midx - 30+60*j, midy -30+60*k);

   /* place the counter inside rectangle */
   setcolor(LIGHTCYAN);
   settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 1);
   settextjustify(CENTER_TEXT, CENTER_TEXT);

   if(c[j][k]==2048)
     e=2;
   if (c[j][k]!=0)
     sprintf(string,"%d ",c[j][k]);
   else
     sprintf(string,"   ");

   outtextxy(midx-60+60*k, midy-60+60*j, string);
 }

 getch();
 closegraph();
 return e;

 }

/*level easy(5*5)*/
int printere(int c[5][5])
{
 int gd = DETECT, gm;
 int e=0;
 int i,j,k, midx, midy, count,minx, miny;

 initgraph(&gd, &gm, "c:\\TURBOC3\\BGI");
 midx = getmaxx()/2;
 midy = getmaxy()/2;
 /* get mid positions in x and y-axis */

 char string[100];

/*setting formatting styles*/
 setcolor(LIGHTCYAN);
 settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 1);
 settextjustify(CENTER_TEXT, CENTER_TEXT);
 sprintf(string,"HIGHSCORE: %d\tSCORE: %d\n",highscoree,score);
 outtextxy(150,50, string);


 for (j = 0; j < 5; j++)
 for (k = 0; k < 5; k++)
 {
   /* draws the grid board */
   setcolor(YELLOW);
   setfillstyle(SOLID_FILL, WHITE);

   rectangle(midx - 150+60*j, midy - 150+60*k, midx - 90+60*j, midy -90+60*k);

   /*to print the numbers inside the boxes*/
   setcolor(LIGHTCYAN);
   settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 1);
   settextjustify(CENTER_TEXT, CENTER_TEXT);

   if(c[j][k]==2048)
     e=2;
   if (c[j][k]!=0)
     sprintf(string,"%d ",c[j][k]);
   else
     sprintf(string,"   ");

   outtextxy(midx-120+60*k, midy-120+60*j, string);
 }

 getch();
 closegraph();
 return e;

 }

// ########################################## LOGIC FUNCTION #################################################

/*level medium (4*4)*/
void logic(int *a)
{

  check=1;
  int i,k,pk;

  for(i=0;i<4;i++)
      r[i]=a[i];

  k=0;

  for(i=0;i<4;i++)
  {
     if(a[i]!=0)
     {
	   a[k]=a[i];
	   k++;
     }
  }

  while(k<4)
  {
     a[k]=0;
     k++;
  }

  k=0;
  pk=0;

  for(i=0;i<4;i++)
  {
      if (i==2)
      {
	    pk=1;
      }

      if(i<3)
      {
	     if(a[i]==a[i+1])
	     {
	        if(i==1)
		       pk=3;
	        a[k]=2*a[i];
	        score+=a[k];
	        if(score>highscore)
			   highscore=score;
	        i++;
	     }
	     else
	     {
	        a[k]=a[i];

         }
	     k++;
      }

      if(((pk==1)&&(i==2))||((pk==3)&&(i==3)))
      {
	     a[k]=a[3];
	     k++;
      }
   }

   while(k<4)
   {
      a[k]=0;
      k++;
   }

   for(i=0;i<4;i++)
   {
       if(a[i]!=r[i])
       {
	      check=0;//if any move is possible then check is set to 0 otherwise check is set to 1
       }
   }
}

/*level difficult (3*3)*/
void logicd(int *a)
{
  check=1;
  int i,k,pk;

  for(i=0;i<3;i++)
      ro[i]=a[i];

  k=0;
  for(i=0;i<3;i++)
  {
     if(a[i]!=0)
     {
	   a[k]=a[i];
	   k++;
     }
  }

  while(k<3)
  {
     a[k]=0;
     k++;
  }

  k=0;
  pk=0;
  for(i=0;i<3;i++)
  {
      if (i==1)
      {
	  pk=1;
      }

      if(i<2)
      {
	     if(a[i]==a[i+1])
	     {
	        if(i==0)
		       pk=3;
	        a[k]=2*a[i];
	        score+=a[k];
	        if(score>highscored)
			    highscored=score;
	        i++;
	     }

	     else
	     {
	        a[k]=a[i];
	     }
	     k++;
      }

      if(((pk==1)&&(i==1))||((pk==3)&&(i==2)))
      {
	     a[k]=a[2];
	     k++;
      }
  }

   while(k<3)
   {
      a[k]=0;
      k++;
   }

   for(i=0;i<3;i++)
   {
       if(a[i]!=ro[i])
       {
	      check=0;
       }
   }
}

/*level easy (5*5)*/
void logice(int *a)
{
  check=1;
  int i,k,pk;

  for(i=0;i<5;i++)
      ra[i]=a[i];
  k=0;

  for(i=0;i<5;i++)
  {
     if(a[i]!=0)
     {
	    a[k]=a[i];
	    k++;
     }
  }

  while(k<5)
  {
     a[k]=0;
     k++;
  }

  k=0;
  pk=0;
  for(i=0;i<5;i++)
  {
      if (i==3)
      {
	     pk=1;
      }

      if(i<4)
      {
	     if(a[i]==a[i+1])
	     {
	        if(i==2)
		       pk=3;
	       a[k]=2*a[i];
	       score+=a[k];
	       if(score>highscoree)
			   highscoree=score;
	       i++;
	     }
	     else
	     {
	       a[k]=a[i];
	     }
	     k++;
      }

      if(((pk==1)&&(i==3))||((pk==3)&&(i==4)))
      {
	     a[k]=a[4];
	     k++;
      }
   }

   while(k<5)
   {
      a[k]=0;
      k++;
   }

   for(i=0;i<5;i++)
   {
       if(a[i]!=ra[i])
       {
	     check=0;
       }
   }
}

// ###################################################TO CHECK FOR END CONDITION#############################################################################

int endd(int a[4][4])
{
    int i,j;
    for(i=0;i<4;i++)
    {
	  for(j=0;j<3;j++)
      {
	     if(a[i][j]==a[i][j+1])
		 return 0;

	     if(a[j][i]==a[j+1][i])
		 return 0;
	  }
    }
    return 1;
}

int enddd(int a[3][3])
{
    int i,j;
    for(i=0;i<3;i++)
    {
	for(j=0;j<2;j++)
	{
	    if(a[i][j]==a[i][j+1])
		return 0;

	    if(a[j][i]==a[j+1][i])
		return 0;
	}
    }
    return 1;
}

int endde(int a[5][5])
{
    int i,j;
    for(i=0;i<5;i++)
    {
	for(j=0;j<4;j++)
	{
	    if(a[i][j]==a[i][j+1])
		return 0;

	    if(a[j][i]==a[j+1][i])
		return 0;
	}
    }
    return 1;
}

//################################ VOID MAIN ################################################################################33

/*level medium*/
void medium()
{
 int ch11,e;
 FILE *f1,*f2;
 f1=fopen("medium.txt","r");
 fscanf(f1,"%d",&highscore);
 fclose(f1);

 check=0;
 int i,j,k;
 int ab[4][4],r[4];

 /*initialize all boxes to zero*/
 for(i=0;i<4;i++)
 {
   for(j=0;j<4;j++)
   {
     ab[i][j]=0;
   }
 }

  printf("\n\n\tGAME CONTROLS:USE ARROW KEYS TO OPERATE THE GAME\n\n\tTO QUIT THE GAME PRESS ESC");
  printf("\n\n\n\n\tTO START THE GAME PRESS ANY KEY:");
  scanf("%d",&ran);

  counter();

  /*to generate 2 at a random position*/
  if(ran==0)
    ran++;
  ran=ran*10;
  m=random();      //generate a random no. from 0 to ran*10-1
  n=m%4;           //value of n will be between 0 to 3
  m=m/(3*ran/10);  //value of m will be between 0 to 3

  while(ab[m][n]!=0)
  {
      m=random();
      n=m%4;
      m=m/(3*ran/10);
  }
  ab[m][n]=2;

  while(ab[m][n]!=0)
  {
      int m=random();
      n=m%4;
      m=m/(3*ran/10);
  }
  ab[m][n]=2;

  end=printer(ab);
  while(end!=2)
  {
    if( kbhit())
    {
      char ch=getch();

      if(ch==75)//Left arrow key
      {
          for(i=0;i<4;i++)
          {
            k=0;
            for(j=0;j<4;j++)
            {
              r[k]=ab[i][j];
              k++;
            }

            logic(r);
            if(check==0)//if a move was possible in the 1D array
               p=1;

            k=0;
            for(j=0;j<4;j++)
            {
              ab[i][j]=r[k];
              k++;
            }
          }

          if(p==1)//if a move is possible in the grid then 2 is generated at a random position
          {
            p=0;
            m=random();
            n=m%4;
            m=m/(3*ran/10);

            while(ab[m][n]!=0)
            {
              m=random();
              n=m%4;
              m=m/(3*ran/10);
            }
            ab[m][n]=2;
          }

        end=printer(ab);//to display the updated grid
     }

    else if(ch==77)//right arrow key
    {
      for(i=0;i<4;i++)
      {
        k=0;
        for(j=3;j>=0;j--)
        {
          r[k]=ab[i][j];
          k++;
        }

        logic(r);
        if(check==0)//if a move was possible in the 1D array
          p=1;

        k=0;
        for(j=3;j>=0;j--)
        {
          ab[i][j]=r[k];
          k++;
        }
      }

      if(p==1)//if a move is possible in the grid then 2 is generated at a random position
      {
        p=0;
        m=random();
        n=m%4;
        m=m/(3*ran/10);

        while(ab[m][n]!=0)
        {
          m=random();
          n=m%4;
          m=m/(3*ran/10);
        }

        ab[m][n]=2;
      }

      end=printer(ab);//to display the upgraded grid
    }

    else if(ch==72)//up arrow key
    {
      for(i=0;i<4;i++)
      {
        k=0;
        for(j=0;j<4;j++)
        {
          r[k]=ab[j][i];
          k++;
        }

        logic(r);

        if(check==0)//if a move was possible in the 1D array
        p=1;

        k=0;
        for(j=0;j<4;j++)
        {
          ab[j][i]=r[k];
          k++;
        }
      }
      if(p==1)//if a move is possible in the grid then 2 is generated at a random position
        {
          p=0;
          m=random();
          n=m%4;
          m=m/(3*ran/10);

          while(ab[m][n]!=0)
          {
            m=random();
            n=m%4;
            m=m/(3*ran/10);
          }

          ab[m][n]=2;
        }

        end=printer(ab);//to display the upgraded grid
    }

    else if(ch==80)//down arrow key
    {
      for(i=0;i<4;i++)
      {
        k=0;
        for(j=3;j>=0;j--)
        {
          r[k]=ab[j][i];
          k++;
        }

        logic(r);
        if(check==0)//if a move was possible in the 1D array
          p=1;

        k=0;
        for(j=3;j>=0;j--)
        {
          ab[j][i]=r[k];
          k++;
        }
      }

      if(p==1)//if a move is possible in the grid then 2 is generated at a random position
      {
        p=0;
        m=random();
        n=m%4;
        m=m/(3*ran/10);

        while(ab[m][n]!=0)
        {
          m=random();
          n=m%4;
          m=m/(3*ran/10);
        }

        ab[m][n]=2;
      }

         end=printer(ab);//to display the upgraded grid
    }

    else if(ch==27)//escape
    {
        goto X;
    }
	else
	{
	   printf("INVALID CONTROLS");
    }

  }
  ch11=0;
  for(i=0;i<4;i++)
	for(j=0;j<4;j++)
     {
	   if(ab[i][j]==0)//if any box is empty
       ch11=1;

     }

  if(ch11!=1)
    e=endd(ab);

  if(e==1)
  {
      over();
      goto X;
  }

 if(end==2)
   win();
 }

X://updating highscore
f2=fopen("medium.txt","w");
fprintf(f2,"%d\n",highscore);
fclose(f2);

}


void easy()
{
    int ch,e;
    FILE *f1,*f2;
    f1=fopen("easy.txt","r");
    fscanf(f1,"%d",&highscoree);
    fclose(f1);
    check=0;
    int i,j,k;
    int ab[5][5],r[5];

    /*to initialize all values to zero*/
    for(i=0;i<5;i++)
    {
       for(j=0;j<5;j++)
       {
          ab[i][j]=0;
       }
    }

    printf("\n\n\tGAME CONTROLS:USE ARROW KEYS TO OPERATE THE GAME\n\n\tTO QUIT THE GAME PRESS ESC");
    printf("\n\n\n\tTO START THE GAME PRESS ANY KEY:");
    scanf("%d",&ran);

    counter();

    /*to generate a 2 at random position*/
    if(ran==0)
       ran++;
    ran=ran*10;
    m= random();
    n=m%5;
    m=m/(2*ran/10);

    while(ab[m][n]!=0)
    {
       m=random();
       n=m%5;
       m=m/(2*ran/10);
    }

    ab[m][n]=2;

    while(ab[m][n]!=0)
    {
       int m=random();
       n=m%5;
       m=m/(2*ran/10);
    }
    ab[m][n]=2;

    end=printere(ab);
    while(end!=2)
    {
       if( kbhit())
       {
          char ch= getch();

          if(ch==75)//left arrow key
          {
             for(i=0;i<5;i++)
		     {
			    k=0;
			    for(j=0;j<5;j++)
			    {
			       r[k]=ab[i][j];
			       k++;
			    }

			    logice(r);
			    if(check==0)
			        p=1;

			    k=0;
			    for(j=0;j<5;j++)
			    {
			       ab[i][j]=r[k];
			       k++;
			    }
		      }

              if(p==1)
		      {
			     p=0;
			     m=random();
			     n=m%5;
			     m=m/(2*ran/10);

			     while(ab[m][n]!=0)
			     {
                    m=random();
			        n=m%5;
			        m=m/(2*ran/10);
			     }
			     ab[m][n]=2;
		      }

		    end=printere(ab);
        }

        else if(ch==77)//right arrow key
        {
            for(i=0;i<5;i++)
            {
			   k=0;
			   for(j=4;j>=0;j--)
			   {
			      r[k]=ab[i][j];
			      k++;
			   }

			   logice(r);
			   if(check==0)
			      p=1;

			   k=0;
			   for(j=4;j>=0;j--)
			   {
			      ab[i][j]=r[k];
			      k++;
			   }
            }

		     if(p==1)
		     {
		       p=0;
		       m=random();
		       n=m%5;
		       m=m/(2*ran/10);

		       while(ab[m][n]!=0)
		       {
                  m=random();
			      n=m%5;
			      m=m/(2*ran/10);
		       }

		       ab[m][n]=2;
		     }

		     end=printere(ab);
        }

        else if(ch==72)//up arrow key
        {
             for(i=0;i<5;i++)
		     {
			    k=0;
			    for(j=0;j<5;j++)
			    {
			       r[k]=ab[j][i];
                   k++;
			    }

			    logice(r);
			    if(check==0)
			       p=1;

			    k=0;
			    for(j=0;j<5;j++)
			    {
			       ab[j][i]=r[k];
			       k++;
			    }
            }

            if(p==1)
            {
			   p=0;
			   m=random();
			   n=m%5;
			   m=m/(2*ran/10);

			  while(ab[m][n]!=0)
			  {
			      m=random();
			      n=m%5;
			      m=m/(2*ran/10);
			  }

			  ab[m][n]=2;
		       }

              end=printere(ab);
        }

        else if(ch==80)//down arrow key
        {
            for(i=0;i<5;i++)
			{
			    k=0;
			    for(j=4;j>=0;j--)
			    {
			      r[k]=ab[j][i];
			      k++;
			    }

			    logice(r);
			    if(check==0)
			       p=1;

			    k=0;
			    for(j=4;j>=0;j--)
			    {
				ab[j][i]=r[k];
				k++;
			    }
			}

			if(p==1)
			{
			    p=0;
			    m=random();
			    n=m%5;
			    m=m/(2*ran/10);

			    while(ab[m][n]!=0)
			    {
			       m=random();
			       n=m%5;
			       m=m/(2*ran/10);
			    }

			    ab[m][n]=2;
			}
		       end=printere(ab);
        }

        else if(ch==27)//escape
        {
            goto X1;
        }

	    else
	    {
	      printf("INVALID CONTROLS");
        }

     }

     ch=0;
     for(i=0;i<5;i++)
	 for(j=0;j<5;j++)
     {
	    if(ab[i][j]==0)
	    ch=1;
     }

     if(ch!=1)
        e=endde(ab);

     if(e==1)
     {
        over();
        goto X1;
     }

     if(end==2)
       win();
   }

X1:
f2=fopen("easy.txt","w");
fprintf(f2,"%d\n",highscoree);
fclose(f2);
}

void difficult()
{
  int ch,e;
  FILE *f1,*f2;
  f1=fopen("difficult.txt","r");
  fscanf(f1,"%d",&highscored);
  fclose(f1);

  check=0;
  int i,j,k;
  int ab[3][3],r[3];

  /*initialize all values to 0*/
  for(i=0;i<3;i++)
  {
    for(j=0;j<3;j++)
    {
     ab[i][j]=0;
    }
  }
  printf("\n\n\tGAME CONTROLS: USE ARROW KEYS TO OPERATE THE GAME\n\n\tTO QUIT THE GAME PRESS ESC");
  printf("\n\n\n\tTO START THE GAME PRESS ANY KEY:");
  scanf("%d",&ran);

  counter();

  /*to generate 2 at any random position*/
  if(ran==0)
    ran++;
  ran=ran*10;
  m= random();
  n=m%3;
  m=m/(4*ran/10);

  while(ab[m][n]!=0)
  {
      m=random();
      n=m%3;
      m=m/(4*ran/10);
  }
  ab[m][n]=2;

  while(ab[m][n]!=0)
  {
      int m=random();
      n=m%3;
      m=m/(4*ran/10);
  }
  ab[m][n]=2;

  end=printerd(ab);
  while(end!=2)
  {
    if( kbhit())
    {
      char ch= getch();

      if(ch==75)//left arrow key
      {
        for(i=0;i<3;i++)
        {
          k=0;
          for(j=0;j<3;j++)
          {
            r[k]=ab[i][j];
            k++;
          }

          logicd(r);
          if(check==0)
            p=1;

          k=0;
          for(j=0;j<3;j++)
          {
            ab[i][j]=r[k];
            k++;
          }
        }
        if(p==1)
        {
			p=0;
			m=random();
			n=m%3;
			m=m/(4*ran/10);

			while(ab[m][n]!=0)
			{
                m=random();
			    n=m%3;
			    m=m/(4*ran/10);
			}
			ab[m][n]=2;

        }
		    end=printerd(ab);
      }

    else if(ch==77)//right arrow key
    {

         for(i=0;i<3;i++)
         {
			 k=0;
			 for(j=2;j>=0;j--)
			 {
			    r[k]=ab[i][j];
			    k++;
			 }

			 logicd(r);
			 if(check==0)
			    p=1;

			 k=0;
			 for(j=2;j>=0;j--)
			 {
			   ab[i][j]=r[k];
			   k++;
			 }
        }

        if(p==1)
        {
		       p=0;
		       m=random();
		       n=m%3;
		       m=m/(4*ran/10);

		       while(ab[m][n]!=0)
		       {
			     m=random();
			     n=m%3;
			     m=m/(4*ran/10);
		       }

		       ab[m][n]=2;
        }

		     end=printerd(ab);
    }

     else if(ch==72)//up arrow key
        {
            for(i=0;i<3;i++)
            {
			    k=0;
			    for(j=0;j<3;j++)
			    {
			      r[k]=ab[j][i];
			      k++;
			    }

			    logicd(r);
			    if(check==0)
			       p=1;
			    k=0;

			    for(j=0;j<3;j++)
			    {
			       ab[j][i]=r[k];
			       k++;
			    }
            }

            if(p==1)
            {
			  p=0;
			  m=random();
			  n=m%3;
			  m=m/(4*ran/10);

			  while(ab[m][n]!=0)
			  {
			      m=random();
			      n=m%3;
			      m=m/(4*ran/10);
			  }

			  ab[m][n]=2;
            }

		       end=printerd(ab);
        }

      else if(ch==80)//down arrow key
        {
            for(i=0;i<3;i++)
			{
			    k=0;
			    for(j=2;j>=0;j--)
			    {
			      r[k]=ab[j][i];
			      k++;
			    }

			    logicd(r);
			    if(check==0)
			       p=1;
			    k=0;

			    for(j=2;j>=0;j--)
			    {
				ab[j][i]=r[k];
				k++;
			    }
			}

			if(p==1)
			{
			    p=0;
			    m=random();
			    n=m%3;
			    m=m/(4*ran/10);

			    while(ab[m][n]!=0)
			    {
			       m=random();
			       n=m%3;
			       m=m/(4*ran/10);
			    }

			    ab[m][n]=2;
			}
		       end=printerd(ab);
        }

      else if(ch==27)//escape
        {
            goto X4;
		}
	  else
	   {
	       printf("INVALID CONTROLS");
       }

    }
      ch=0;
      for(i=0;i<3;i++)
	  for(j=0;j<3;j++)
      {
	    if(ab[i][j]==0)
	    ch=1;
      }

      if(ch!=1)
         e=enddd(ab);
      if(e==1)
      {
         over();
         goto X4;
      }

      if(end==2)
         win();
   }

X4:
f2=fopen("difficult.txt","w");
fprintf(f2,"%d\n",highscored);
fclose(f2);
}

void counter()
{
    int gd = DETECT, gm;
    int i, midx, midy, count;
    char string[100];

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    /* get mid positions in x and y-axis */
    midx = getmaxx()/2;
    midy = getmaxy()/2;


    for (i = 5; i >= 0; i--)
    {
        setcolor(WHITE);
        rectangle(midx - 50, midy - 50, midx + 50, midy + 50);
        floodfill(midx, midy, WHITE);

        /* place the counter inside rectangle */
        setcolor(BLUE);
        sprintf(string, "%s", "Counter");
        settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 3);
        settextjustify(CENTER_TEXT, CENTER_TEXT);
        outtextxy(midx, midy - 100, "GAME IS GOING TO START IN....");

        /* print the counter value */
        sprintf(string, "%d", i);
        outtextxy(midx, midy, string);

	    /* delay for a second(1000 milli second) */
	    delay(1000);

	    /* clears screen */
        cleardevice();
    }

    closegraph();

}

void win()
{
   int gd = DETECT, gm;
   int x = 300, y = 200;

   initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

   settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 5);
   settextjustify(CENTER_TEXT, CENTER_TEXT);
   setcolor(CYAN);
   outtextxy(x, y, "Y O U  W O N");

   /*delay for two seconds(2000 millisecond)*/
   delay(2000);
   getch();
   closegraph();
}

void over()
{
   int gd = DETECT, gm;
   int x = 300, y = 200;

   initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

   settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 5);
   settextjustify(CENTER_TEXT, CENTER_TEXT);
   setcolor(RED);
   outtextxy(x, y, "G A M E  O V E R");

   /*delay for two seconds(2000 milli second)*/
   delay(2000);
   getch();
   closegraph();
}

void level()
{
    int gd = DETECT, gm;
    int i, midx, midy, count;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    /* get mid positions in x and y-axis */
    midx = getmaxx()/2;
    midy = getmaxy()/2;

    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 5);
    settextjustify(CENTER_TEXT, CENTER_TEXT);
    setcolor(GREEN);
    outtextxy(midx-120, midy - 120, "L E V E L S");

    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
    outtextxy(midx-70,midy-70," E A S Y - 5");
    outtextxy(midx-40,midy-40," M E D U I M - 4");
    outtextxy(midx-10,midy-10," D I F F I C U L T - 3");

	/*delay for a second(1000 millisecond*/
	delay(1000);
	getch();
	cleardevice();

    printf("\n\n\t ENTER YOUR CHOICE:");
    scanf("%d",&choice);

	cleardevice();
    closegraph();
}

void frontpage()
{
    int gd=DETECT,gm;
    int i,x,y,midx, midy;

    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

    while (!kbhit())
    {
      /* color 500 random pixels on screen */
      for(i=0; i<=500; i++)
      {
        x=rand()%getmaxx();
	    y=rand()%getmaxy();
	    putpixel(x,y,15);/*generate white pixels at random positions on the screen*/
      }

      delay(500);

      midx=getmaxx()/2;
      midy=getmaxx()/2;
      settextstyle(SANS_SERIF_FONT,HORIZ_DIR,10);
      settextjustify(CENTER_TEXT,CENTER_TEXT);
      setcolor(RED);
      outtextxy(midx-10,midy-100,"2048");

      delay(2000);
      cleardevice();
    }

   getch();
   clrscr();
   closegraph();

}

void main()
{

frontpage();

level();

 if(choice==4)
    medium();//4*4

 if(choice==5)
    easy();//5*5

 if(choice==3)
	difficult();//3*3

}
