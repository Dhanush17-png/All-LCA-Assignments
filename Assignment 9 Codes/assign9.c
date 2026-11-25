
#include <stdio.h>

struct Field
{
    int id;
    float moisture;
    float temperature;
    float humidity;
    int cropHealth;
    float latitude;
    float longitude;
};

int main()
{
    struct Field f;
    FILE *fp, *report;
    int n, i;

    printf("Enter number of fields: ");
    scanf("%d", &n);

    fp = fopen("fielddata.txt", "w");

    if(fp == NULL)
    {
        printf("File cannot be opened.\n");
        return 1;
    }

    for(i = 0; i < n; i++)
    {
        printf("\nEnter details for Field %d:\n", i + 1);

        printf("Field ID: ");
        scanf("%d", &f.id);

        printf("Soil Moisture: ");
        scanf("%f", &f.moisture);

        printf("Temperature: ");
        scanf("%f", &f.temperature);

        printf("Humidity: ");
        scanf("%f", &f.humidity);

        printf("Crop Health: ");
        scanf("%d", &f.cropHealth);

        printf("Latitude: ");
        scanf("%f", &f.latitude);

        printf("Longitude: ");
        scanf("%f", &f.longitude);

        fprintf(fp, "%d %f %f %f %d %f %f\n",
                f.id, f.moisture, f.temperature,
                f.humidity, f.cropHealth,
                f.latitude, f.longitude);
    }

    fclose(fp);

    fp = fopen("fielddata.txt", "r");
    report = fopen("fieldreport.txt", "w");

    if(fp == NULL || report == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    printf("\n--- FIELD MONITORING REPORT ---\n");

    fprintf(report, "--- FIELD MONITORING REPORT ---\n");

    while(fscanf(fp, "%d %f %f %f %d %f %f",
                 &f.id, &f.moisture, &f.temperature,
                 &f.humidity, &f.cropHealth,
                 &f.latitude, &f.longitude) == 7)
    {
        printf("\nField ID: %d\n", f.id);
        printf("Soil Moisture: %.2f\n", f.moisture);
        printf("Temperature: %.2f\n", f.temperature);
        printf("Humidity: %.2f\n", f.humidity);
        printf("Crop Health: %d\n", f.cropHealth);
        printf("GPS: %.4f, %.4f\n",
               f.latitude, f.longitude);

        fprintf(report, "\nField ID: %d\n", f.id);
        fprintf(report, "Soil Moisture: %.2f\n", f.moisture);
        fprintf(report, "Temperature: %.2f\n", f.temperature);
        fprintf(report, "Humidity: %.2f\n", f.humidity);
        fprintf(report, "Crop Health: %d\n", f.cropHealth);
        fprintf(report, "GPS: %.4f, %.4f\n",
                f.latitude, f.longitude);

        if(f.moisture < 30)
        {
            printf("Status: Irrigation Required\n");
            fprintf(report, "Status: Irrigation Required\n");
        }
        else
        {
            printf("Status: No Irrigation Required\n");
            fprintf(report, "Status: No Irrigation Required\n");
        }
    }

    fclose(fp);
    fclose(report);

    printf("\nField report saved successfully.\n");

    return 0;
}
