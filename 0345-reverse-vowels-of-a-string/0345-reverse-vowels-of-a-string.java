class Solution {
    public String reverseVowels(String s) {
        char[] array = s.toCharArray();

        int start = 0;
        int end = array.length - 1;

        while (start < end) {

            while (start < end && !isVowels(array[start])) {
                start++;
            }

            while (start < end && !isVowels(array[end])) {
                end--;
            }

            if (start < end) {
                char temp = array[start];
                array[start] = array[end];
                array[end] = temp;

                start++;
                end--;
            }
        }

        return new String(array);
    }

    private boolean isVowels(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            return true;
        } else {
            return false;
        }
    }
}