// https://codility.com/programmers/task/frog_jmp
int solution(int X, int Y, int D) {
    int left = Y - X;
    if (left <= 0) return 0;
    int jumps = left / D;
    if (left % D > 0) jumps++;
    
    return jumps;    
}
