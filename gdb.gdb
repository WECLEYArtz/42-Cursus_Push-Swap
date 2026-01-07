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
	set $node = stack_a
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


# 32540
# 47763
# 45074

# 19142
# 38459
# 395
# 44948
# 31812
# 20555
# 19067
# 35346
# 17996
# 35651
# 44500
# 43415
# 41471
# 3934
# 24932
# 18617
# 18087
# 13597
# 6413
# 47818
# 40035
# 4572
# 17890
# 43928
# 38847
# 39628
# 45436
# 28818
# 45000
# 13669
# 7545
# 24155
# 31633
# 15602
# 32359
# 18099
# 40582
# 7190
# 43460
# 8129
# 32003
# 42945
# 27415
# 25284
# 40325
# 10538
# 21507
# 5572
# 26578
# 31650
# 14791
# 1666
# 27253
# 29646
# 15458
# 16537
# 49831
# 45753
# 7191
# 33900
# 2275
# 29738
# 45548
# 25728
# 574
# 49388
# 7398
# 6234
# 3213
# 44747
# 43652
# 9545
# 44150
# 14372
# 36777
# 6039
# 4902
# 14341
# 35244
# 3380
# 21600
# 48701
# 44263
# 9999
# 13836
# 1027
# 39378
# 41915
# 11354
# 3351
# 35457
# 15830
# 30274
# 5754
# 8828
# 36585
# 17264
