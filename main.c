#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct player
{
    int power,attack,deff,id,stts;
    char namep[10];
    struct player *head,*next,*tail,*temp,*baru;
}player;
typedef struct room
{
    int power,attack,deff,stts,id;
    char namep[10];
    struct room *headp,*nextp,*prev,*tempp,*ruang,*tempa;
}room;

player *next,*head,*tail,*temp,*baru;
room *headp = NULL,*nextp,*prev,*tempp,*ruang,*tempa;

void view ()
{
    temp = head;
    printf("No   Nama\tPower\tAttack\tDeff\tStatus\n\n");
    while (temp != NULL)
    {
        printf("%d   %s\t%d\t%d\t%d\t%d\n",temp->id,temp->namep,temp->power,temp->attack,temp->deff,temp->stts);
        temp=temp->next;
    }
}

int main()
{
    //Character
    int play=0,pil,x,no=1;
    head= (player*) malloc(sizeof(player));
    head->power = 200;head->attack = 47;head->deff = 50;
    strcpy(head->namep, "Matumbaman");
    head->id = 1;
    head->stts = 0;
    baru= (player*) malloc(sizeof(player));
    head->next = baru;
    baru->id = 2;
    baru->stts = 0;
    baru->power = 200; baru->attack = 52; baru->deff = 45;
    strcpy(baru->namep, "Arteezy");
    temp=baru;
    baru= (player*) malloc(sizeof(player));
    strcpy(baru->namep, "Sumail");
    baru->id = 3;
    baru->stts = 0;
    temp->next = baru;
    baru->power = 200; baru->attack = 49; baru->deff = 44;
    temp=baru;
    baru= (player*) malloc(sizeof(player));
    temp->next = baru;
    baru->id = 4;
    baru->stts = 0;
    strcpy(baru->namep, "Iceiceice");
    baru->power = 200; baru->attack = 57; baru->deff = 35;
    temp=baru;
    baru= (player*) malloc(sizeof(player));
    temp->next = baru;
    baru->id = 5;
    baru->stts = 0;
    strcpy(baru->namep, "Miracle-");
    baru->power = 200; baru->attack = 52; baru->deff = 42;
    temp=baru;
    baru= (player*) malloc(sizeof(player));
    temp->next = baru;
    baru->id = 6;
    baru->stts = 0;
    strcpy(baru->namep, "MidOne");
    baru->power = 200; baru->attack = 54; baru->deff = 49;
    baru->next = NULL;
    system("cls");
    view();

    //Pemilihan Character
    while (play != 2)

    {
        do
        {
            printf("\n\tPlayer %d : ", play+1);
            scanf("%d", &pil);
            //Jika memilih character yang sama dan pilihan yang dipilih tidak ada
            if(pil <=0 || pil > 6 || pil == x)
            {
                system("cls");
                view();
                tempp=headp;
                if(play = 1)
                {
                    printf("\n\tPlayer %d :\n",play);
                    printf("\t%s\n\tPower : %d\n\tAttack : %d\n\tDeffense : %d\n\n",tempp->namep,tempp->power, tempp->attack, tempp->deff);
                }
            }
        }while(pil <= 0 || pil > 6 || pil == x);
        x=pil;
        play++;
        pilihan(pil);
        system("cls");
        view();
        tempp=headp;
        do
        {
            printf("\n\tPlayer %d :\n",no);
            printf("\t%s\n\tPower : %d\n\tAttack : %d\n\tDeffense : %d\n\n",tempp->namep,tempp->power, tempp->attack, tempp->deff);
            tempp=tempp->nextp;
            if(temp==NULL)
                break;
            no++;
        }while(tempp != headp);
    }
    duel();
    return 0;
}

void pilihan (int pil)
{
    temp=head;
    int i;
    while (temp != NULL)
    {
        if(temp->id == pil)
        {
            temp->stts = 1;
            ruang = (room*) malloc(sizeof(room));
            ruang->attack = temp->attack;
            ruang->deff = temp->deff;
            ruang->power = temp->power;
            ruang->id=i;
            strcpy(ruang->namep,temp->namep);
            i++;
            break;
        }
        temp=temp->next;
    }
    if(headp == NULL)
    {
        headp = ruang;
        ruang->stts = 0;
        ruang->nextp=NULL;
    }
    else
    {
        headp->nextp = ruang;
        ruang->stts=1;
        ruang->nextp=headp;
    }
}
void duel ()
{
    char pil;
    int no,temp[2];
    int serang[2],bertahan[2],x,stts=0;
    char back;
    tempp=headp;
    ruang=tempp->nextp;
    //proses bertarung
    while(tempp->power > 1)
    {
        def:
        no=1;
        system("cls");
        tempa=headp;
        do
        {
            printf("\n\tPlayer %d :\n",no);
            printf("\t%s\n\tPower : %d\tAttack : %d\tDeffense : %d\n\n",tempa->namep,tempa->power, tempa->attack, tempa->deff);
            tempa=tempa->nextp;
            no++;
        }while(tempa != headp );
        //giliran setiap pemain
        printf("Player %d Turn\n", tempp->stts+1);
        //pilih serang atau bertahan
        printf("\n1. Serang\n2. Bertahan");
        printf("\nPilihan : ");
        pil=getch();
        x=tempp->stts;
        switch(pil)
        {
            case '1': serang[x]=tempp->attack;
                    temp[x]=1;
                    break;
            case '2': bertahan[x]=tempp->deff;
                    temp[x]=2;
                    break;
            default : goto def;
        }
        tempp->power = tempp->power - 5;
        //proses pengurangan power
        if(stts==1)
        {
            stts=0;
            if(temp[0] == 1 && temp[1] ==1)
            {
                ruang->power=ruang->power - serang[0];
                headp->power=headp->power - serang[1];
            }
            else if(temp[0] == 1 && temp[1] ==2)
            {
                serang[0]=serang[0] - ruang->deff;
                if(serang[0] > 0)
                    ruang->power=ruang->power - serang[0];
            }
            else if(temp[0] == 2 && temp[1] ==1)
            {
                serang[1]=serang[1] - headp->deff;
                if(serang[1] > 0)
                    headp->power=headp->power - serang[1];
            }
        }
        else
            stts++;

        if(ruang->power < 0 || ruang->power == 0 )
        {
            ruang->power=0;
        }
        if(headp->power < 0 || headp->power == 0)
        {
            headp->power = 0;
        }
        tempp=tempp->nextp;
    }
    system("cls");
    no=1;
    do
    {
        printf("\n\tPlayer %d :\n",no);
        printf("\t%s\n\tPower : %d\tAttack : %d\tDeffense : %d\n\n",tempa->namep,tempa->power, tempa->attack, tempa->deff);
        tempa=tempa->nextp;
        no++;
    }while(tempa != headp );
    //announcement
    if (headp->power == 0 && ruang->power == 0)
        printf("Power is Equal, the final Result was Draw\n\n");
    else if(ruang->power == 0)
        printf("Congratulation The Winner is Player 1\n\n");
    else if (headp->power==0)
        printf("Congratulation The Winner is Player 2\n\n");
    tempa->power = 200;

    printf("Play Again ? [Y/N] : "); fflush(stdin);
    scanf("%c", &back);
    if(back == 'Y' || back=='y')
        main();
    else
        return 0;
}
