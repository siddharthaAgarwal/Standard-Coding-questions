

	/* 
    
    class Node 
    	int data;
    	Node left;
    	Node right;
	*/

    static void levOrder(TreeMap<Integer,Integer> m, Node root)
    {
        if(root==null)
        return;


        class Pair
        {
            Node first;
            int second;
            public Pair(Node a,int b)
            {
                first=a;
                second=b;
            }
        }


        Queue<Pair> q=new LinkedList<>();
        q.offer(new Pair(root,0));

        while(!q.isEmpty())
        {
            Node curr=q.peek().first;
            int ind=q.poll().second;
      
            if(!m.containsKey(ind))
                m.put(ind,curr.data);

            if(curr.left!=null)
            {
               // levOrder(m,root.left,ind-1);
                q.offer(new Pair(curr.left,ind-1));
            }
            if(curr.right!=null)
            {
                //levOrder(m,root.right,ind+1);
                q.offer(new Pair(curr.right,ind+1));
            }
         
         
        }

    }

	public static void topView(Node root) {
      
      TreeMap<Integer,Integer> hm= new TreeMap<>();

      levOrder(hm,root);

      for(Map.Entry<Integer, Integer> h: hm.entrySet())
      {
          System.out.print(h.getValue()+" ");
      }


      
    }


