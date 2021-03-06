// Source : https://leetcode.com/problems/video-stitching/
// Author : Mading
// Date   : 2020-01-28

/********************************************************************************** 
* 1024. Video Stitching [Medium]
* You are given a series of video clips from a sporting event that lasted T seconds.  
* These video clips can be overlapping with each other and have varied lengths.

* Each video clip clips[i] is an interval: it starts at time clips[i][0] and 
* ends at time clips[i][1].  We can cut these clips into segments freely: 
* for example, a clip [0, 7] can be cut into segments [0, 1] + [1, 3] + [3, 7].

* Return the minimum number of clips needed so that we can cut the clips into 
* segments that cover the entire sporting event ([0, T]).  If the task is impossible, return -1.


* Example 1:
* Input: clips = [[0,2],[4,6],[8,10],[1,9],[1,5],[5,9]], T = 10
* Output: 3
* Explanation: 
* We take the clips [0,2], [8,10], [1,9]; a total of 3 clips.
* Then, we can reconstruct the sporting event as follows:
* We cut [1,9] into segments [1,2] + [2,8] + [8,9].
* Now we have segments [0,2] + [2,8] + [8,10] which cover the sporting event [0, 10].

* Example 2:
* Input: clips = [[0,1],[1,2]], T = 5
* Output: -1
* Explanation: 
* We can't cover [0,5] with only [0,1] and [0,2].

* Example 3:
* Input: clips = [[0,1],[6,8],[0,2],[5,6],[0,4],[0,3],[6,7],[1,3],[4,7],[1,4],[2,5],[2,6],[3,4],[4,5],[5,7],[6,9]], T = 9
* Output: 3
* Explanation: 
* We can take clips [0,4], [4,7], and [6,9].

* Example 4:
* Input: clips = [[0,4],[2,8]], T = 5
* Output: 2
* Explanation: 
* Notice you can have extra video after the event ends.
 
* Note:
* 1 <= clips.length <= 100
* 0 <= clips[i][0], clips[i][1] <= 100
* 0 <= T <= 100
* 
*               
**********************************************************************************/

// 12 ms, faster than 11.31% of C++, 10.2 MB, less than 33.33% of C++
bool cmp(vector<int> vec1,vector<int> vec2){
    if(vec1[0] == vec2[0]){
        return vec1[1]<vec2[1];
    }
    return vec1[0]<vec2[0];
}
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        sort(clips.begin(),clips.end(),cmp);
        int minsize = 0;
        int lastpoint = 0;
        for(int i=0;i<clips.size();){
            if(clips[i][0] > lastpoint){
                return -1;
            }
            int m = 0;
            while(i < clips.size() && clips[i][0] <= lastpoint){
                if(clips[i][1] > m){
                    m = clips[i][1];
                }
                i++;
            }
            lastpoint = m;
            minsize++;
            if(lastpoint >= T){
                return minsize;
            }
        }
        if(lastpoint < T){
            return -1;
        }
        return minsize;
        
    }
};



// 4 ms, faster than 73.24% of C++, 8.9 MB, less than 100.00% of C++
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        int currst,currend=INT_MIN;
        int isClipFound=false;
        for(int i=0;i<clips.size();i++){
            if(clips[i][0]==0){
                isClipFound=true;
                currend=max(currend,clips[i][1]);
            }
        }
        if(!isClipFound)
            return -1;
        int s=1;
        int end=currend;
        while(end<T){
            int isClipFound=false;
            for(int i=0;i<clips.size();i++){
                if(clips[i][0]<=end && currend<clips[i][1]){
                    isClipFound=true;
                    currend=clips[i][1];
                    currst=clips[i][0];
                }
            }
            if(!isClipFound){
                return -1;
            }
            s++;
            end=currend;
        }
        return s;       
    }
};