dir_name = Dir::pwd
contest_name = dir_name.split("/").last
contest_category = dir_name.split("/").last[...3]
contest_number = dir_name.split("/").last[3...]
unless /\A(ABC|ARC|AGC)\z/ === contest_category.chomp
  contest_category = "other"
  contest_number = 0
end

url_prefix = "https://atcoder.jp/contests/#{contest_name.downcase}/tasks/"
links = Array.new

Dir::glob("./*").select{ |f| FileTest.directory?(f) }.map{ |s| s[2..] }.each do |task_name|
  if /\A[A-Z]\z/ === task_name.chomp
    links.push(["#{url_prefix}#{contest_name.downcase}_#{task_name.downcase}", task_name])
  end
end

links.each do |url, task_name|
  Dir.chdir("#{dir_name}/#{task_name}"){ system("oj dl #{url}") }
end