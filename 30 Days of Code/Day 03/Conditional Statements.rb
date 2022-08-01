n = gets.chomp.to_i

# Task 1
if n%2 != 0
puts "Weird"

# Task 2
elsif n%2 ==0 && n<=5 && n>=2
puts "Not Weird"

#Task 3
elsif n%2 ==0 && n<=20 && n>=6
puts "Weird"

#Task 4
elsif n%2==0 && n>20
puts "Not Weird"
end
