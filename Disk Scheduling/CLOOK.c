#include <stdio.h>
#include <stdlib.h>

#define LOW 0
#define HIGH 199

int main()
{
  int queue[20], head, q_size, i,j, seek=0, diff, max, min, range, temp, queue1[20], queue2[20], temp1=0, temp2=0;
  
  float avg;

  printf("%s\t", "Input the number of disk locations");
  scanf("%d", &q_size);

  printf("%s\t", "Enter initial head position");
  scanf("%d", &head);

  printf("%s\n", "Enter disk positions to read");

  for(i=0; i<q_size; i++){
    scanf("%d", &temp);
    //queue1 - elems greater than head
    if(temp >= head){
      queue1[temp1] = temp;
      temp1++;
    } else {
      queue2[temp2] = temp;
      temp2++;
    }
  }


  //sort queue1 - increasing order

  for(i=0; i<temp1-1; i++){
    for(j=i+1; j<temp1; j++){
      if(queue1[i] > queue1[j]){
        temp = queue1[i];
        queue1[i] = queue1[j];
        queue1[j] = temp;
      }
    }
  }

  //sort queue2
  for(i=0; i<temp2-1; i++){
    for(j=i+1; j<temp2; j++){
      if(queue2[i] > queue2[j]){
        temp = queue2[i];
        queue2[i] = queue2[j];
        queue2[j] = temp;
      }
    }
  }

  if(abs(head-LOW) <= abs(head-HIGH))
  {

    for(i=1,j=temp2-1; j>=0; i++,j--)
	{
        queue[i] = queue2[j];
    }

    queue[i] = LOW;
    queue[i+1] = HIGH;
for(i=temp2+3,j=temp1-1; j&gt;=0; i++,j--)
{
queue[i] = queue1[j];
}
}
else
{
for(i=1,j=0; j&lt;temp1; i++,j++)
{
queue[i] = queue1[j];
}
queue[i] = HIGH;
queue[i+1] = LOW;
for(i=temp1+3,j=0; j&lt;temp2; i++,j++)

{
queue[i] = queue2[j];
}

}
queue[0] = head;
printf(&quot;Execution order : %d&quot;,queue[0]);

for(j=0; j&lt;=q_size+1; j++)
{
diff=abs(queue[j+1] - queue[j]);
seek += diff;
printf(&quot;--&gt; %d&quot;,queue[j+1]);
}
printf(&quot;\nTotal seek time is %d\n&quot;, seek);
avg = seek/(float)q_size;
printf(&quot;Average seek time is %f\n&quot;, avg);
return 0;
}

