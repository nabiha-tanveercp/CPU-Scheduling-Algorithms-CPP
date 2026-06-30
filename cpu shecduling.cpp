#include<iostream>
using namespace std;
int main() {
	int n;
	int choice;
	int t = 0;
	int count = 0;
	int count1 = 0;
	int quantum;
	int completed = 0;
	cout << "enter number of processes:" << endl;
	cin >> n;
	int* processid = new int[n];
	int* arraivaltime = new int[n];
	int* bursttime = new int[n];
	int* remainingtime = new int[n];
	int* completiontime = new int[n]();//Allocate the array and initialize every element to its default value for unintialization because we have if (remainingtime[current] == 0)completiontime[current] = t; for current to not to get warn we use this value initialization feature.
	int* readyqueue = new int[n]();
	int current;
	for (int i = 0; i < n; i++)
	{
		processid[i] = i + 1;
	}
	cout << "Enter choice '1' for FCFS,'2' for SJF non-preemptive , '3' for SRTF preemptive, '4' for round robin" << endl;
	cin >> choice;
	if (choice == 1)

	{//for FCFS arraival
		for (int i = 0; i < n;i++) {
			cout << "Enter the arrival time for Process" << i + 1 << endl;
			cin >> arraivaltime[i];
		}
		for (int i = 0; i < n;i++) {
			cout << "Enter the burst time for Process" << i + 1 << endl;
			cin >> bursttime[i];
		}
		// bubble sorting
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = 0; j < n - i - 1; j++)
			{
				if (arraivaltime[j] > arraivaltime[j + 1])
				{
					int temp;

					temp = arraivaltime[j];
					arraivaltime[j] = arraivaltime[j + 1];
					arraivaltime[j + 1] = temp;

					temp = bursttime[j];
					bursttime[j] = bursttime[j + 1];
					bursttime[j + 1] = temp;

					temp = processid[j];
					processid[j] = processid[j + 1];
					processid[j + 1] = temp;
				}
			}
		}
		// process exexcution
		for (int i = 0; i < n;i++) {
			int count = 0;
			for (int j = i + 1;j < n;j++) {
				if (arraivaltime[i] < arraivaltime[j])
				{
					count = count + 1;
				}
			}
			if (count == n - (i + 1))
			{
				t = t + bursttime[i];
				completiontime[i] = t;
			}

		}
		// table to show
		cout << " |Pr|A.T|B.T|C.T|" << endl;
		for (int i = 0; i < n; i++)

		{
			int tat = completiontime[i] - arraivaltime[i];
			int wt = tat - bursttime[i];
			cout << " |P" << processid[i] << "|" << arraivaltime[i] << " | " << bursttime[i] << " | " << completiontime[i] << " | " << tat << " | " << wt << " | "<<endl;
		}
	}//SJF non preemptive
	else if (choice == 2)
	{
		for (int i = 0; i < n;i++) {
			cout << "Enter the arrival time for Process" << i + 1 << endl;
			cin >> arraivaltime[i];
		}
		for (int i = 0; i < n;i++) {
			cout << "Enter the burst time for Process" << i + 1 << endl;
			cin >> bursttime[i];
		}
		// bubble sorting
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = 0; j < n - i - 1; j++)
			{
				if (arraivaltime[j] > arraivaltime[j + 1])
				{
					int temp;

					temp = arraivaltime[j];
					arraivaltime[j] = arraivaltime[j + 1];
					arraivaltime[j + 1] = temp;

					temp = bursttime[j];
					bursttime[j] = bursttime[j + 1];
					bursttime[j + 1] = temp;

					temp = processid[j];
					processid[j] = processid[j + 1];
					processid[j + 1] = temp;
				}
			}
		}
		// process execution

		t = t + bursttime[0];
		completiontime[0] = t;

		for (int i = 1; i < n; i++)
		{
			int shortest = i;

			for (int j = i + 1; j < n; j++)
			{
				if (arraivaltime[j] <= t)
				{
					if (bursttime[j] < bursttime[shortest])
					{
						shortest = j;
					}
				}
			}

			if (shortest != i)
			{
				int temp;

				temp = bursttime[i];
				bursttime[i] = bursttime[shortest];
				bursttime[shortest] = temp;

				temp = arraivaltime[i];
				arraivaltime[i] = arraivaltime[shortest];
				arraivaltime[shortest] = temp;

				temp = processid[i];
				processid[i] = processid[shortest];
				processid[shortest] = temp;
			}

			t = t + bursttime[i];
			completiontime[i] = t;
		}




		cout << " |Pr|A.T|B.T|C.T|" << endl;
		for (int i = 0; i < n; i++)

		{
			int tat = completiontime[i] - arraivaltime[i];
			int wt = tat - bursttime[i];
			cout << " |P" << processid[i] << "|" << arraivaltime[i] << " | " << bursttime[i] << " | " << completiontime[i] << " | " << tat << "|" << wt <<" | "<< endl;
		}


	}//SRTF PREEMPTIVE
	else if (choice == 3)
	{
		for (int i = 0; i < n;i++) {
			cout << "Enter the arrival time for Process" << i + 1 << endl;
			cin >> arraivaltime[i];
		}
		for (int i = 0; i < n;i++) {
			cout << "Enter the burst time for Process" << i + 1 << endl;
			cin >> bursttime[i];
		}

		// bubble sorting
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = 0; j < n - i - 1; j++)
			{
				if (arraivaltime[j] > arraivaltime[j + 1])
				{
					int temp;

					temp = arraivaltime[j];
					arraivaltime[j] = arraivaltime[j + 1];
					arraivaltime[j + 1] = temp;

					temp = bursttime[j];
					bursttime[j] = bursttime[j + 1];
					bursttime[j + 1] = temp;

					temp = processid[j];
					processid[j] = processid[j + 1];
					processid[j + 1] = temp;
				}
			}
		}
		// copying after sorting 
		for (int i = 0; i < n;i++) {

			remainingtime[i] = bursttime[i];
		}
		int t1 = 0;

		for (int i = 0; i < n; i++)
		{
			t1 = t1 + bursttime[i];
		}

		// process execution
		for (int i = 0; i < t1; i++)
		{

			int current = -1;

			// Find the shortest available process
			for (int j = 0; j < n; j++)
			{
				if (arraivaltime[j] <= t && remainingtime[j] > 0)
				{
					if (current == -1 || remainingtime[j] < remainingtime[current])
					{
						current = j;
					}
				}
			}

			// If no process has arrived yet
			if (current == -1)
			{
				t++;
				continue;
			}

			// Execute ONE unit
			remainingtime[current]--;

			t++;

			// Check completion
			if (remainingtime[current] == 0)
			{
				completiontime[current] = t;
			}
		}




		cout << " |Pr|A.T|B.T|C.T|" << endl;
		for (int i = 0; i < n; i++)

		{
			int tat = completiontime[i] - arraivaltime[i];
			int wt = tat - bursttime[i];
			cout << " |P" << processid[i] << "|" << arraivaltime[i] << " | " << bursttime[i] << " | " << completiontime[i] << " | " << tat << " | " << wt <<" | "<< endl;
		}
	}
	// round robin
	else if (choice == 4)
	{
		for (int i = 0; i < n;i++) {
			cout << "Enter the arrival time for Process" << i + 1 << endl;
			cin >> arraivaltime[i];
		}
		for (int i = 0; i < n;i++) {
			cout << "Enter the burst time for Process" << i + 1 << endl;
			cin >> bursttime[i];
		}

		// bubble sorting
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = 0; j < n - i - 1; j++)
			{
				if (arraivaltime[j] > arraivaltime[j + 1])
				{
					int temp;

					temp = arraivaltime[j];
					arraivaltime[j] = arraivaltime[j + 1];
					arraivaltime[j + 1] = temp;

					temp = bursttime[j];
					bursttime[j] = bursttime[j + 1];
					bursttime[j + 1] = temp;

					temp = processid[j];
					processid[j] = processid[j + 1];
					processid[j + 1] = temp;
				}
			}
		}
		// copying after sorting 
		for (int i = 0; i < n;i++) {

			remainingtime[i] = bursttime[i];
		}
		cout << "enter times slice" << endl;
		cin >> quantum;
		int t1 = 0;

		for (int i = 0; i < n; i++)
		{
			t1 = t1 + bursttime[i];
		}
		int j = 0;

		// Insert all processes that have already arrived (usually arrival time = 0)
		while (j < n && arraivaltime[j] <= t)
		{
			readyqueue[count] = j;
			count++;
			j++;
		}

		// Main Round Robin Loop
		while (completed < n)
		{
			// If ready queue is empty, move time forward
			if (count == 0)
			{
				t++;

				while (j < n && arraivaltime[j] <= t)
				{
					readyqueue[count] = j;
					count++;
					j++;
				}

				continue;
			}

			// Take first process
			current = readyqueue[0];

			// Remove first process (shift queue)
			for (int k = 0; k < count - 1; k++)
			{
				readyqueue[k] = readyqueue[k + 1];
			}

			count--;

			// Execute for one quantum
			count1 = 0;

			while (count1 < quantum && remainingtime[current] > 0)
			{
				remainingtime[current]--;

				t++;
				count1++;

				// Check newly arriving processes
				while (j < n && arraivaltime[j] <= t)
				{
					readyqueue[count] = j;
					count++;
					j++;
				}
			}

			// Check completion
			if (remainingtime[current] == 0)
			{
				completiontime[current] = t;
				completed++;
			}
			else
			{
				// Put process back into queue
				readyqueue[count] = current;
				count++;
			}
		}

		// Display Table
		cout << " |Pr|A.T|B.T|C.T|TAT|WT|" << endl;

		for (int i = 0; i < n; i++)

		{
			int tat = completiontime[i] - arraivaltime[i];
			int wt = tat - bursttime[i];
			cout << " |P" << processid[i] << "|" << arraivaltime[i] << " | " << bursttime[i] << " | " << completiontime[i] << " | "<< tat <<" | "<< wt<<" | "<< endl;
		}
		}
	delete[]processid;
	delete[]completiontime;
	delete[] remainingtime;
	delete[]bursttime;
	delete readyqueue;
	delete[]arraivaltime;

}
	