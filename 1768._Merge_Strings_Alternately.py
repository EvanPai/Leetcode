class Solution(object):
    def mergeAlternately(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: str
        """
        
        result = []
        i = 0
        j = 0

        while i<len(word1) and j<len(word2):
            result.append(word1[i])
            result.append(word2[j])

            i += 1
            j += 1

        result.extend(word1[i:])
        result.extend(word2[j:])

        return ''.join(result)
            