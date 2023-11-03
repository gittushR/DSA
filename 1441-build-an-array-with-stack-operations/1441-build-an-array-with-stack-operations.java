class Solution {
    public List<String> buildArray(int[] target, int n) {
    final List<String> result = new ArrayList<>();
    int index = 1;
    for(int e: target) {
        while(e != index) {
            result.add("Push");
            result.add("Pop");
            index++;
        }
        result.add("Push");
        index++;
    }
    return result;
}
}