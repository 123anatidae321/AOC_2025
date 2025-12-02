use strict;
use warnings;

use POSIX qw/ceil/;
my $file = $ARGV[0];

die "Input file is not specified" unless($file);

open FILE, "$file" or die "Failed to open $file: $!";

my @ranges = split ",", <FILE>;

close FILE;

my $result = 0;
foreach (@ranges) {
    m/^(\d+)-(\d+)$/;
    foreach ($1..$2) {
        my $chunk_length = ceil(0.5*length);
        next unless (m/^(\d{$chunk_length})\1$/);
        $result += $_;
    }
}

print "Result is $result\n";