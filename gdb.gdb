define stacka
	set $node = *($stack_a)
	while $node
		p *(int *) (* $node ) ->content
		set $node = $node->next
	end
end

define stackb
	set $node = *($stack_b)
	while $node
		p *(int *) (* $node ) ->content
		set $node = $node->next
	end
end

define savestack
	set $stack_a = &stack_a
	set $stack_b = &stack_b
end

define disprec
	display *(int *)work_node->content
	display index
	display moves
	display cheapest
end


define parsed
	display *valid
	display i
	display &(*argv)[i]
	display *(int *)(* new)->content
end
