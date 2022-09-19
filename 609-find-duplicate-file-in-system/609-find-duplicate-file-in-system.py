class Solution:
    def findDuplicate(self, paths: List[str]) -> List[List[str]]:
        ans = []
        mp = dict()
        for info in paths:
            pth = info[0:info.find(' ')] + '/'
            info = info[info.find(' ')+1:]
            # print(pth)
            while info!='' and info.find('(') != -1:
                idx = info.find('(')
                idx2 = info.find(')')
                pth2 = pth + info[:idx]
                txt = info[idx+1:idx2]
                if txt in mp.keys():
                    mp[txt].append(pth2)
                else:
                    mp[txt] = [pth2]
                info = info[idx2+2:]
        ans = []
        for x in mp.keys():
            if len(mp[x]) > 1:
                ans.append(mp[x])
        return ans
            