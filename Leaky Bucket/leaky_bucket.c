//Leaky bucket
#include <stdio.h>
int main() {
int no_of_queries, storage, output_pkt_size;
int bucket_size, size_left;
printf("Enter the number of queries: ");
scanf("%d", &no_of_queries);
printf("Enter the bucket size: ");
scanf("%d", &bucket_size);
printf("Enter the output packet size: ");
scanf("%d", &output_pkt_size);
storage = 0;
for (int i = 0; i < no_of_queries; i++) {
int input_pkt_size;
printf("\nEnter the input packet size for iteration %d: ", i + 1);
scanf("%d", &input_pkt_size);
size_left = bucket_size - storage;
if (input_pkt_size <= size_left) {
storage += input_pkt_size;
} else {
int packets_added = bucket_size - storage;
printf("Bucket full! Only %d packets added. Packet loss = %d\n", packets_added,
input_pkt_size - packets_added);
storage = bucket_size; // Bucket is full, so set storage to bucket_size
}
printf("Buffer size = %d out of bucket size = %d\n",storage, bucket_size);
storage -= output_pkt_size;
if (storage < 0) {
storage = 0; // Ensure storage does not go below 0
}
printf("Remaining packets in the bucket after output removal: %d\n", storage);
}
return 0;}