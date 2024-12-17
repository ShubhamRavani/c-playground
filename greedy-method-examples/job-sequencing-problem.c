#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to represent a job
typedef struct
{
    int id;       // Job ID
    int deadline; // Deadline of the job
    int profit;   // Profit of the job
} Job;

// Function to compare jobs based on profit (for sorting)
int compareJobs(const void *a, const void *b)
{
    Job *jobA = (Job *)a;
    Job *jobB = (Job *)b;
    return jobB->profit - jobA->profit; // Sort in descending order of profit
}

// Function to find the maximum deadline
int findMaxDeadline(Job jobs[], int n)
{
    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
    {
        if (jobs[i].deadline > maxDeadline)
        {
            maxDeadline = jobs[i].deadline;
        }
    }
    return maxDeadline;
}

// Job Sequencing function
void jobSequencing(Job jobs[], int n)
{
    // Sort jobs by profit in descending order
    qsort(jobs, n, sizeof(Job), compareJobs);

    // Find the maximum deadline to create the time slot array
    int maxDeadline = findMaxDeadline(jobs, n);
    int slots[maxDeadline + 1];         // Time slots (1-based indexing)
    bool slotOccupied[maxDeadline + 1]; // Slot availability

    // Initialize slots and occupied status
    for (int i = 0; i <= maxDeadline; i++)
    {
        slots[i] = -1; // No job assigned
        slotOccupied[i] = false;
    }

    int totalProfit = 0;
    int jobCount = 0;

    // Assign jobs to slots
    for (int i = 0; i < n; i++)
    {
        // Find a free slot for this job (starting from its deadline)
        for (int j = jobs[i].deadline; j > 0; j--)
        {
            if (!slotOccupied[j])
            {
                slots[j] = jobs[i].id;         // Assign job ID to the slot
                slotOccupied[j] = true;        // Mark the slot as occupied
                totalProfit += jobs[i].profit; // Add profit
                jobCount++;                    // Increment job count
                break;
            }
        }
    }

    printf("Selected jobs: ");
    for (int i = 1; i <= maxDeadline; i++)
    {
        if (slotOccupied[i])
        {
            printf("J%d ", slots[i]);
        }
    }
    printf("\nTotal profit: %d\n", totalProfit);
}

int main()
{
    int n;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    Job jobs[n];
    printf("Enter the job details (ID, deadline, profit):\n");
    for (int i = 0; i < n; i++)
    {
        printf("Job %d - ID: ", i + 1);
        scanf("%d", &jobs[i].id);
        printf("Job %d - Deadline: ", i + 1);
        scanf("%d", &jobs[i].deadline);
        printf("Job %d - Profit: ", i + 1);
        scanf("%d", &jobs[i].profit);
    }

    jobSequencing(jobs, n);

    return 0;
}
