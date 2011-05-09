#! /usr/bin/env ruby

require 'fileutils'

FileUtils::mkdir('bin') unless File::exists?('bin')

Dir['src/*.cpp'].each do |path|
    src = path
    binary = './bin/' + File::basename(path).sub('.cpp', '')
    next if FileUtils::uptodate?(binary, [src])
    puts src
    system("gcc -o #{binary} #{src} -lstdc++")
end
