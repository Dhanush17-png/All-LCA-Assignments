#include <stdio.h>
#include <unistd.h>

union Sensor
{
    float vf, ir, vr;
};

struct Device
{
    int id, type;
    float vf, ir, vr;
    int status;
};

int main()
{
    struct Device d[50];
    union Sensor s;

    int n, i, j;
    int pass = 0, fail = 0;
    float maxVf, maxIr, minVr;

    printf("Enter number of devices: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("\nEnter Device ID: ");
        scanf("%d", &d[i].id);

        printf("1.Diode  2.BJT  3.MOSFET  4.LED\n");
        printf("Enter device type: ");
        scanf("%d", &d[i].type);

        switch(d[i].type)
        {
            case 1:
                maxVf = 0.8;
                maxIr = 5;
                minVr = 50;
                break;

            case 2:
                maxVf = 0.9;
                maxIr = 10;
                minVr = 50;
                break;

            case 3:
                maxVf = 4.0;
                maxIr = 1;
                minVr = 60;
                break;

            case 4:
                maxVf = 3.6;
                maxIr = 10;
                minVr = 5;
                break;
        }

        d[i].status = 1;

        for(j = 0; j < 2; j++)
        {
            printf("\nReading Set %d\n", j + 1);

            printf("Enter Vf: ");
            scanf("%f", &s.vf);
            d[i].vf = s.vf;

            printf("Enter Ir: ");
            scanf("%f", &s.ir);
            d[i].ir = s.ir;

            printf("Enter Vr: ");
            scanf("%f", &s.vr);
            d[i].vr = s.vr;

            if(d[i].vf > maxVf ||
               d[i].ir > maxIr ||
               d[i].vr < minVr)
            {
                d[i].status = 0;
            }

            if(j < 1)
            {
                printf("Waiting for 2 seconds...\n");
                sleep(2);
            }
        }

        if(d[i].status == 1)
            pass++;
        else
            fail++;
    }

    printf("\nID\tType\tVf\tIr\tVr\tStatus\n");

    for(i = 0; i < n; i++)
    {
        printf("%d\t%d\t%.2f\t%.2f\t%.2f\t",
               d[i].id, d[i].type,
               d[i].vf, d[i].ir, d[i].vr);

        if(d[i].status == 1)
            printf("PASS\n");
        else
            printf("FAIL\n");
    }

    printf("\nPASS DEVICES:\n");
    for(i = 0; i < n; i++)
        if(d[i].status == 1)
            printf("%d\n", d[i].id);

    printf("\nFAIL DEVICES:\n");
    for(i = 0; i < n; i++)
        if(d[i].status == 0)
            printf("%d\n", d[i].id);

    printf("\nTotal PASS: %d", pass);
    printf("\nTotal FAIL: %d\n", fail);

    return 0;
}
