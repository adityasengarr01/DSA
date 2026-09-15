class Solution {
    public int maxPerformance(int n, int[] speed, int[] efficiency, int k) {
        long max = 0;

        Integer[] index = new Integer[n];

        for (int i = 0; i < n; i++) {
            index[i] = i;
        }

        Arrays.sort(index, (a, b) -> efficiency[b] - efficiency[a]);

        PriorityQueue<Integer> list = new PriorityQueue<>();

        long speedsum = 0;

        for (int i : index) {
            list.add(speed[i]);
            speedsum += speed[i];

            if (list.size() > k) {
                speedsum -= list.poll();
            }

            max = Math.max(max, speedsum * efficiency[i]);
        }

        return (int)(max % 1000000007);
    }
}