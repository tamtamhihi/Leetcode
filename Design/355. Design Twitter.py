from collections import defaultdict
from queue import PriorityQueue

class Post:
    def __init__(self, id, author, time):
        self.id = id
        self.author = author
        self.time = time
    # When put in PriorityQueue, the latest post will be on top.
    def __lt__(self, other):
        return self.time > other.time

class Twitter:
    def __init__(self):
        self.time = 0
        # Map a userId with set of users they follow
        self.follows = defaultdict(set)
        
        # Map a userId with their posts
        self.post = defaultdict(list)

    def postTweet(self, userId: int, tweetId: int) -> None:
        self.time += 1
        self.post[userId].append(Post(tweetId, userId, self.time))

    def getNewsFeed(self, userId: int) -> List[int]:
        feed = []
        feed_pointers = dict()
        feed_candidates = PriorityQueue()
        
        # Add the latest post of each followee, and the user themselves,
        # to the priority queue and mark the index
        for followee in self.follows[userId]:
            feed_pointers[followee] = len(self.post[followee]) - 1
            if len(self.post[followee]) > 0:
                feed_candidates.put(self.post[followee][-1])
        feed_pointers[userId] = len(self.post[userId]) - 1
        if len(self.post[userId]) > 0:
            feed_candidates.put(self.post[userId][-1])
        
        # Retrieve each post from top of priority queue
        for i in range(10):
            if len(feed_candidates.queue) == 0:
                break
            post = feed_candidates.get()
            feed.append(post.id)
            # Append the next latest post by this author
            if feed_pointers[post.author] > 0:
                feed_pointers[post.author] -= 1
                pointer = feed_pointers[post.author]
                feed_candidates.put(self.post[post.author][pointer])
        return feed

    def follow(self, followerId: int, followeeId: int) -> None:
        self.follows[followerId].add(followeeId)

    def unfollow(self, followerId: int, followeeId: int) -> None:
        if followeeId in self.follows[followerId]:
            self.follows[followerId].remove(followeeId)
