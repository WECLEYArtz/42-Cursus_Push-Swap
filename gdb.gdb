define stack_a
	set $node = stacks.a 
	while $node
		p *(int *) (* $node ) ->content
		set $node = $node->next
	end
end

define stack_b
	set $node = stacks.b 
	while $node
		p *(int *) (* $node ) ->content
		set $node = $node->next
	end
end

define stack_x
	while $node
		p *(int *) (* $node ) ->content
		set $node = $node->next
	end
end

define disprec
	display *(int *)work_node->content
	display index
	display moves
	display cheapest
end

# -1 -10 23 22 11 5 3 10 12 2 4 9 1 0 6 400
